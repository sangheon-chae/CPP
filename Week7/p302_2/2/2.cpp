#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct WordPair {
    string eng; 
    string kor; 
};

const int MAXWORDS = 100; 

class MyDic {
    WordPair words[MAXWORDS];
    int nWords;               

public:
    
    MyDic() : nWords(0) {}


    inline void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        }
    }

   
    inline void load(string filename) {
        ifstream fin(filename);
        if (fin.is_open()) {
            while (nWords < MAXWORDS && fin >> words[nWords].eng >> words[nWords].kor) {
                nWords++;
            }
            fin.close();
        }
    }

 
    inline void store(string filename) {
        ofstream fout(filename);
        if (fout.is_open()) {
            for (int i = 0; i < nWords; i++) {
                fout << words[i].eng << " " << words[i].kor << endl;
            }
            fout.close();
        }
    }

    inline void print() {
        cout << "--- 나의 단어장 ---" << endl;
        for (int i = 0; i < nWords; i++) {
            cout << i << ": " << words[i].eng << " - " << words[i].kor << endl;
        }
    }

    
    inline string getEng(int index) {
        if (index >= 0 && index < nWords) return words[index].eng;
        return "";
    }

   
    inline string getKor(int index) {
        if (index >= 0 && index < nWords) return words[index].kor;
        return "";
    }

    inline int getCount() { return nWords; }
};



int main() {
    MyDic dic;

    // 1. 단어 추가 테스트
    dic.add("apple", "사과");
    dic.add("banana", "바바나");
    dic.add("computer", "컴퓨터");

    // 2. 현재 단어장 출력 테스트
    cout << "--- 초기 단어장 ---" << endl;
    dic.print();

    // 3. 단어장 저장 테스트
    dic.store("my_dic.txt");
    cout << "\n단어장을 'my_dic.txt'에 저장했습니다." << endl;

    
    cout << "\n1번째 인덱스 단어 확인:" << endl;
    cout << "English: " << dic.getEng(1) << endl;
    cout << "Korean: " << dic.getKor(1) << endl;

    return 0;
}