#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // {장르명, {재생횟수, 고유번호}}
    map<string, vector<pair<int,int>>> albumorder;
    
    for(int i = 0; i < genres.size(); i++)
    {
        albumorder[genres[i]].push_back({plays[i], i});
    }
    
    // 장르별 총 재생횟수
    map<string, int> genretotal;
    for(auto& list : albumorder)
    {
        int total = 0;
        for(auto& info : list.second) 
        {
            total += info.first;
        }
        genretotal[list.first] += total;
        
    }
    
    // 장르 순서 내림차순 정렬
    vector<pair<int, string>> genrerank;
    for(auto& genre : genretotal)
    {
        genrerank.push_back({genre.second, genre.first});
    }
    sort(genrerank.rbegin(), genrerank.rend());
    
    // 장르 내에서 정렬 재생횟수 내림차->고유번호 오름차
    for(auto& song : albumorder)
    {
        sort(song.second.begin(), song.second.end(), [](auto& a, auto& b)
             {
                 if(a.first != b.first) return a.first > b.first;
                 return a.second < b.second;
             });
    }
    
    for(auto& genre : genrerank)
    {
        auto& songs = albumorder[genre.second];
        for (int i = 0; i < songs.size() && i < 2; i++) answer.push_back(songs[i].second);
    }
    return answer;
}