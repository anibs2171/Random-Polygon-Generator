#include<bits/stdc++.h>
using namespace std;


bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

bool generatewkt(int n){
	srand(time(0));
	vector< pair <int,int> > wkt;
	vector< pair <int,int> > points;
	vector<int> x,y;

	vector< pair <int,int> > one;
	vector< pair <int,int> > two;
	vector< pair <int,int> > three;
	vector< pair <int,int> > four;

	vector< pair <int,int> > vect;
	vector< pair <int,int> > vecty;

	for(int i=0;i<n;i++){
		int r= rand();
		x.push_back(r);
	}
	for(int i=0;i<n;i++){
		int r= rand();
		y.push_back(r);
	}

	for(int i=0;i<n;i++){
		points.push_back( make_pair(x[i],y[i]) );
	}

	vect=points;
	vecty=points;

	sort(vect.begin(), vect.end());
	sort(vecty.begin(), vecty.end(),sortbysec);

	int xmin=vect[0].first;int y_xmin=vect[0].second;
	int xmax=vect[n-1].first;int y_xmax=vect[n-1].second;

	int ymin=vecty[0].second;int x_ymin=vecty[0].first;
	int ymax=vecty[n-1].second;int x_ymax=vecty[n-1].first;

	for(int i=0;i<points.size();i++){
		if(points[i]==vect[0] || points[i]==vect[n-1] || points[i]==vecty[0] || points[i]==vecty[n-1]){
			;
		}
		else{
			one.push_back(points[i]);
		}
	}

	sort(one.begin(), one.end());
	/*
	cout<<"x min point : "<<xmin<<", "<<y_xmin<<endl;
	cout<<"x max point : "<<xmax<<", "<<y_xmax<<endl;
	cout<<"y min point : "<<x_ymin<<", "<<ymin<<endl;
	cout<<"y max point : "<<x_ymax<<", "<<ymax<<endl;
	*/
	wkt.push_back(vect[0]);
	for(int i=0;i<one.size();i++){
		//check if falls in first region...if yes add to wkt
		if(one[i].first>=vect[0].first && one[i].first<=vecty[n-1].first && one[i].second>=vect[0].second && one[i].second<=vecty[n-1].second){
			wkt.push_back(one[i]);
		}
		else{
			two.push_back(one[i]);
		}
	}


	sort(two.begin(), two.end());
	wkt.push_back(vecty[n-1]);
	for(int i=0;i<two.size();i++){
		//check if falls in second region...if yes add to wkt
		if(two[i].first>=vecty[n-1].first && two[i].first<=vect[n-1].first && two[i].second<=vecty[n-1].second && two[i].second>=vect[n-1].second){
			wkt.push_back(two[i]);
		}
		else{
			three.push_back(two[i]);
		}
	}

	sort(three.rbegin(), three.rend());
	wkt.push_back(vect[n-1]);
	for(int i=0;i<three.size();i++){
		//check if falls in third region...if yes add to wkt
		if(three[i].first<=vect[n-1].first && three[i].first>=vecty[0].first && three[i].second<=vect[n-1].second && three[i].second>=vecty[0].second){
			wkt.push_back(three[i]);
		}
		else{
			four.push_back(three[i]);
		}
	}


	sort(four.rbegin(), four.rend());
	wkt.push_back(vecty[0]);
	for(int i=0;i<four.size();i++){
		//check if falls in four region...if yes add to wkt
		if(four[i].first<=vecty[0].first && four[i].first>=vect[0].first && four[i].second>vecty[0].second && four[i].second<=vect[0].second){
			wkt.push_back(four[i]);
		}
	}

	wkt.erase(unique(wkt.begin(),wkt.end()),wkt.end());
	wkt.push_back(vect[0]);
	
	if(wkt.size()==n+1){
		cout<<n<<"-> "<<endl;
		cout<<"POLYGON ((";
		for(int i=0;i<wkt.size();i++){
			cout<<" "<<wkt[i].first<<" "<<wkt[i].second<<", ";

		}
		cout<<"))"<<endl;
		return true;
	}
	else{
		return false;
	}



}


int main(){
	
	for(int i=10;i<=500;i++){

		clock_t start=clock();
		bool val=generatewkt(i);
		clock_t end=clock();
		if(val==true){
			cout<<endl;
			double time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
			cout<<"Time : "<<time<<endl;
			continue;

		}
		else{
			i--;
		}
	}
	
	return 0;
}