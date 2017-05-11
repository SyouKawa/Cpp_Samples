#include"PPIC.h"
#include<stdio.h>
using namespace cv;
using namespace std;

PIC& Query_init(PIC& query);
vector<string>& split_input(string& c, vector<string>& filename);
int main() {
	PIC query("query.jpg");
	Query_init(query);

	vector<string> pic_name(0);
	vector<PIC> pic_sources(0);
	ifstream infile("PicName.txt");
	string c;

	while (getline(infile, c)) split_input(c, pic_name);
	infile.close();
	//debug using/ for (int i(0); i < pic_name.size(); ++i) std::cout << pic_name[i] << endl;
	for (int i(0); i < pic_name.size(); ++i) {
		PIC temp(pic_name[i]);
		pic_sources.push_back(temp);
	}
	/*/debug using/ for (int i(0); i < pic_sources.size(); ++i) {
		std::cout << pic_sources[i] << endl;
		imshow(pic_sources[i].pic_name, pic_sources[i].srcImage);
	}*/

	int minHessian = 500;
	SurfFeatureDetector detector(minHessian);  
	SurfDescriptorExtractor extractor;
	for (int i(0); i < pic_name.size(); ++i) {
		detector.detect(pic_sources[i].srcImage, pic_sources[i].keypoints);
		extractor.compute(pic_sources[i].srcImage, pic_sources[i].keypoints, pic_sources[i].descriptors);
	}

	vector< DMatch > matches;
	FlannBasedMatcher matcher;
	for (int i(0); i < pic_name.size(); ++i) {
		matcher.match(pic_sources[i].descriptors,query.descriptors, matches);
		double max_dist = 0; double min_dist = 100;
		for (int i = 0; i < pic_sources[i].descriptors.rows; i++)
		{
			double dist = matches[i].distance;
			if (dist < min_dist) min_dist = dist;
			if (dist > max_dist) max_dist = dist;
		}
		printf(">Max dist ����ƥ�� : %f \n", max_dist);
		printf(">Min dist ���ƥ�� : %f \n", min_dist);

		std::vector< DMatch > good_matches;
		for (int i = 0; i < pic_sources[i].descriptors.rows; i++)
		{
			if (matches[i].distance < 3 * min_dist)
			{
				good_matches.push_back(matches[i]);
			}
		}
		cout << "ƥ���������Ϊ��" << good_matches.size() << "����" << endl << endl;
		//if (good_matches.size() > 2) cout << pic_name[0] << endl;
		//good_matches.clear();
		//matches.clear();
		//for (int i(0); i < pic_name.size(); ++i) {
			//���Ƴ�ƥ�䵽�Ĺؼ���
			Mat img_matches;
			drawMatches(query.srcImage, query.keypoints, pic_sources[0].srcImage, pic_sources[0].keypoints,
				good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
				vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

			//���������ֲ�����
			vector<Point2f> obj;
			vector<Point2f> scene;

			//��ƥ��ɹ���ƥ����л�ȡ�ؼ���
			for (unsigned int i = 0; i < good_matches.size(); i++)
			{
				obj.push_back((pic_sources[0].keypoints)[good_matches[i].queryIdx].pt);
				scene.push_back((query.keypoints)[good_matches[i].trainIdx].pt);
			}

			Mat H = findHomography(obj, scene, CV_RANSAC);//����͸�ӱ任

														  //�Ӵ���ͼƬ�л�ȡ�ǵ�
			vector<Point2f> obj_corners(4);
			obj_corners[0] = cvPoint(0, 0); obj_corners[1] = cvPoint(query.srcImage.cols, 0);
			obj_corners[2] = cvPoint(query.srcImage.cols, query.srcImage.rows); obj_corners[3] = cvPoint(0, query.srcImage.rows);
			vector<Point2f> scene_corners(4);

			//����͸�ӱ任
			perspectiveTransform(obj_corners, scene_corners, H);

			//���Ƴ��ǵ�֮���ֱ��
			line(img_matches, scene_corners[0] + Point2f(static_cast<float>(query.srcImage.cols), 0), scene_corners[1] + Point2f(static_cast<float>(query.srcImage.cols), 0), Scalar(255, 0, 123), 4);
			line(img_matches, scene_corners[1] + Point2f(static_cast<float>(query.srcImage.cols), 0), scene_corners[2] + Point2f(static_cast<float>(query.srcImage.cols), 0), Scalar(255, 0, 123), 4);
			line(img_matches, scene_corners[2] + Point2f(static_cast<float>(query.srcImage.cols), 0), scene_corners[3] + Point2f(static_cast<float>(query.srcImage.cols), 0), Scalar(255, 0, 123), 4);
			line(img_matches, scene_corners[3] + Point2f(static_cast<float>(query.srcImage.cols), 0), scene_corners[0] + Point2f(static_cast<float>(query.srcImage.cols), 0), Scalar(255, 0, 123), 4);

			//��ʾ���ս��
			imshow("show", img_matches);
	}

	cv::waitKey();
	system("pause");
	return 0;
	}

vector<string>& split_input(string& c, vector<string>& filename) {
	string::size_type i(0);
	int flag(0);
	while (i != c.size()) {
		for (; i != c.size() && isspace(c[i]); ++i);
		string::size_type j = i;
		for (; j != c.size() && !isspace(c[j]); ++j);
		filename.push_back(c.substr(i, j - i));
		i = j;
	}
	return filename;
}

PIC& Query_init(PIC& query) {
	int minHessian = 500;
	SurfFeatureDetector detector(minHessian);
	SurfDescriptorExtractor extractor;
	detector.detect(query.srcImage, query.keypoints);
	extractor.compute(query.srcImage, query.keypoints, query.descriptors);

	return query;
}