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

	int minHessian = 1000;
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
		printf(">Max dist 最优匹配 : %f \n", max_dist);
		printf(">Min dist 最差匹配 : %f \n", min_dist);

		//【7】存下匹配距离小于3*min_dist的点对
		std::vector< DMatch > good_matches;
		for (int i = 0; i < pic_sources[i].descriptors.rows; i++)
		{
			if (matches[i].distance < 3 * min_dist)
			{
				good_matches.push_back(matches[i]);
			}
		}
		cout << "匹配的特征点为：" << good_matches.size() << "个。" << endl << endl;
		if (good_matches.size() > 2) cout << pic_name[0] << endl;
		good_matches.clear();
		matches.clear();
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
	int minHessian = 9000;
	SurfFeatureDetector detector(minHessian);
	SurfDescriptorExtractor extractor;
	detector.detect(query.srcImage, query.keypoints);
	extractor.compute(query.srcImage, query.keypoints, query.descriptors);

	return query;
}