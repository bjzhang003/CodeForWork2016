/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include<string>
#include<queue>
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//success
class Word_Ladder {
public:
	//生成所有的下一步可以到达的数据
	vector<string> NextCan(string s1)
	{
		vector<string> result;
		for (int i = 0; i < s1.size(); i++)
		{
			for (int j = 'a'; j <= 'z'; j++)
			{
				//更换一个字母
				string Temp = s1;
				Temp[i] = (char)j;
				//存储当前单词
				result.push_back(Temp);
			}
		}
		return result;		
	}
	//判断阶梯的长度
	int ladderLength(string beginWord, string endWord, unordered_set<string> & wordList)
	{
		if (wordList.size() > 0)
		{
			//使用带标记的广度优先来进行查找数据
			queue<pair<string, int>> TempSave;

			//把最后一个数据添加进来
			wordList.insert(endWord);
			TempSave.push({ beginWord,1 });

			//开始广度优先遍历操作
			while (!TempSave.empty())
			{
				auto Temp = TempSave.front();
				cout << "string = " << Temp.first << " ,Level = " << Temp.second << endl;


				//根据当前的单词，生成所有的它下一步可以到达的单词
				vector<string> NextCanStr = NextCan(Temp.first);
				for (auto it = NextCanStr.begin(); it != NextCanStr.end(); it++)
				{
					if (wordList.find(*it) != wordList.end())
					{
						//如果当前单词是可以找到的
						if (*it == endWord)
						{
							return Temp.second + 1;
						}
						else
						{
							//把当前可以到达的数据入队列
							TempSave.push({ *it,Temp.second + 1 });
							//删除已经使用过的单词数据
							wordList.erase(*it);
						}
					}
					//结束if (wordList.find(*it) != wordList.end())
				}
				//结束for (auto it = NextCanStr.begin(); it != NextCanStr.end(); it++)

				//弹出数据
				TempSave.pop();
			}
			//结束while (!TempSave.empty())

		}
		return 0;
	}
};

/*
Word_Ladder Test;
string beginWord = "cet";
string endWord = "ism";
unordered_set<string> wordList = {"kid","tag","pup","ail","tun","woo","erg","luz","brr",
"gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die",
"war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali",
"pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui",
"ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana",
"gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh",
"sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax",
"jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye",
"oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for",
"joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara",
"dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire",
"irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy",
"nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop",
"but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew",
"web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub",
"ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam",
"new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip",
"cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set",
"qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro",
"few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum",
"rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox",
"ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram",
"let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam",
"zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao",
"aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who",
"bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur",
"ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax",
"mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin",
"mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi",
"yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly",
"rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum",
"rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid",
"sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew",
"hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug",
"gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig",
"lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con",
"ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal",
"sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism",
"err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min",
"com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran",
"lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed",
"goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo",
"lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her",
"nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy",
"foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft",
"alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee",
"pin","dun","pat","ten","mob" };
Test.ladderLength(beginWord, endWord, wordList);
*/