#include<iostream>
using namespace std;
#include<string>
#include<vector>

//code recursion,common pitfall:forget to code "return" when you do recursive call

template<class T>
void print_vector(vector<T> &v){
  for(int i = 0,n = v.size(); i < n; ++i){
    cout << v[i];
    if(i != n) {
      cout<<" ";
    }
  }
  cout << endl;
}


void print_set(string s){
  cout<<"{";
  for(int i = 0;i < s.length();++i){
    cout<<s[i];
    if(i != s.length()-1) {
      cout<<",";
    }
  }
  cout << "}" << endl;
}

void print_set(vector<char>& s){
  cout<<"{";
  for(int i = 0;i < s.size();++i){
    cout<<s[i];
    if(i != s.size()-1) {
      cout<<",";
    }
  }
  cout << "}" << endl;
}

int sum_vector(vector<int> &v) {
  int sum = 0;
  for(int i : v){
    sum += i;
  }
  return sum;
}

void coinflip(string sofar,int n) {
    if(n == 0) {
        cout<<sofar<<endl;
        return;
    }
    coinflip(sofar+"H",n-1);
    coinflip(sofar+"T",n-1);
}

void coinflip(int n) {
    coinflip("",n);
}




bool isPalindrome(string s) {
 if(s.length() <= 1) {
    return true;
 }

 if(s[0] != s[s.length() - 1]) {
    return false;
 }
return isPalindrome(s.substr(1,s.length()- 2));
}

//return the index of the key if exists, otherwise return -1

int binaryFind(vector<int>& v,int key,int low, int high) {
  if(low > high) {
    return -1;
  } 
  int mid = low + (high - low) /2;
  if(key < v[mid]) {
    return binaryFind(v,key,low,mid - 1);
  } else if(key > v[mid]) {
    return binaryFind(v,key,mid + 1,high);
  } else {
    return mid;
  }

}

int binaryFind(vector<int>& v,int key) {
    return binaryFind(v,key,0,v.size() - 1);
}

//树形递归结构
// 理解 permute 函数的关键在于意识到其操作构成了一种树形结构，
//其中每个节点代表一个函数调用，节点的子节点代表该函数内部进一步的函数调用。
//对于 "abc" 的排列，这棵树的最上层可以被视为三个主要的分支：
// 将 'a' 作为排列的第一个字符（soFar = 'a'），然后对 'b' 和 'c' 的所有可能排列进行递归。
// 将 'b' 作为排列的第一个字符（soFar = 'b'），然后对 'a' 和 'c' 的所有可能排列进行递归。
// 将 'c' 作为排列的第一个字符（soFar = 'c'），然后对 'a' 和 'b' 的所有可能排列进行递归。

void permute(string soFar,string rest) {
  //first step : base case
  if(rest == "") {
    cout<<soFar<<endl;
    return;
  }
  for(int i = 0; i < rest.length();i++) {
   string newRest = rest.substr(0,i) + rest.substr(i + 1);
  permute(soFar + rest[i],newRest);
  }
}
/*递归调用的核心逻辑
每一步都遵循同样的逻辑：
从 rest字符串中选择一个字符。
将该字符添加到 soFar 字符串中。
对 rest 字符串的剩余部分进行递归处理。*/


void permute(string s) {
    permute("",s);
}



//permute2
// 这里使用swap真正的含义是索引k处放哪个字符
/*在递归体中，函数遍历从 k 到字符串末尾的每个位置 i
并执行以下步骤：
调用 swap 函数交换索引 k 和索引 i 处的字符。
此时 k 位置的字符固定，而 s.substr(k+1) 部分字符将在下一层的递归中继续排列。
递归调用 permute(s, k+1)，以生成以 s[k] 开始的所有排列。
再次调用 swap 函数将索引 k 和索引 i 处的字符交换回来，
这样做是为了恢复字符串的原始顺序，以便于下一次的交换和排列。*/

//the key to this function is freezing one character at a certain place each time .核心在于“固定”

void swap(string& s,int i,int j) {
  int temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

//permute all characters in our string "starting at index k".Print all resulting permutations
void permute(string& s,int k) {
//k is the first of all indices in our string that remain to be permuted.
//if k == s.length() (which is not a valid index in our string) ,that means we have done all the work ,
//then should return to previous recursive calls

//first we code base case
int size = s.length();
if(k == size) {
    cout << s <<endl;
    return;
}


//of the remaining characters (from index k onward),
//let's select each of them to be swapped down into index k and make a recursive call
//for each of those options.
for(int i = k; i < size; ++i) {
    swap(s,k,i);
    permute(s,k + 1);
    swap(s,k,i);//在递归调用 permute(s, k + 1) 之后，进行第二次 swap(s, k, i) 的调用是为了恢复字符串到原始状态（撤销之前的交换），
    //以保证接下来的迭代可以从没被交换过的原始状态开始。这种做法被称作“回溯”。
    //而每次递归完成后，第二个 swap 会撤销当前的字符交换，让 for 循环可以继续尝试将索引 k 上的字符与 i 上的其他字符交换。
}
}






/*工作原理的示例
让我们通过 "abc" 的排列来理解这个过程。初始调用 permute2("abc") 将会调用 permute("abc", 0)。
初始调用 (k = 0):
索引 i 将从 0 遍历到 2。我们开始时有三个选择：将 'a', 'b', 或 'c' 放置在第一个位置。
第一层递归:
第一个递归调用保持 'a' 在索引 0 (k = 0, i = 0)，字符串不变："abc"
第二个递归调用交换 'a' 和 'b'（k = 0, i = 1），字符串变为："bac"
第三个递归调用交换 'a' 和 'c'（k = 0, i = 2），字符串变为："cba"
第二层递归:
对于每个已交换的字符串（例如，"abc"），函数会尝试将选定的第一个字符之后（k = 1）的所有字符再进行排列。
接下来的递归调用将固定第一个字符，然后在第二个位置上交换剩下的字符（对于 "abc"，这会是 'b' 和 'c'）。
这个交换和递归的过程继续进行，直到排列的最后一位。每次到达递归的底部时，我们都打印出一个完整的排列。*/

/*permute("abc", 0):
  swap("abc", 0, 0) --> permute("abc", 1):
    swap("abc", 1, 1) --> permute("abc", 2) --> print "abc"
    swap("abc", 1, 2) --> permute("acb", 2) --> print "acb"
  swap("abc", 0, 1) --> permute("bac", 1):
    swap("bac", 1, 1) --> permute("bac", 2) --> print "bac"
    swap("bac", 1, 2) --> permute("bca", 2) --> print "bca"
  swap("abc", 0, 2) --> permute("cba", 1):
    swap("cba", 1, 1) --> permute("cba", 2) --> print "cba"
    swap("cba", 1, 2) --> permute("cab", 2) --> print "cab"*/



void permute2(string s) {
    //the 0 in the function call below indicates that we start our permutation process by choosing a character 
    //to freeze into place at index 0. Our recursive call will move forward to 
    //choose other characters to freeze into place at the remaining indices.

    permute(s,0);
}






//rollD6  
//parameter "n" indicates that how many turns you want to roll the dice
void rollD6(string sofar,int n) {
//base case
if(n == 0) {
  cout << sofar << endl;
  return;
}

for(int i = 1; i <= 6; ++i) {
 rollD6(sofar + to_string(i) + " ",n - 1);
}
}



//wrapper function
void rollD6(int n) {
  rollD6("",n);
}

//rollD62
void RollD6(string sofar,int n,vector<string>& result) {
 if(n == 0) {
  // fix the redundent white space at the end of the sofar
  if(!sofar.empty() && sofar.back() == ' ') {
    sofar.pop_back();
  }
   result.push_back(sofar);
   return;
 }
 
 for(int i = 1; i <= 6; ++i) {

 RollD6(sofar + to_string(i) + " ",n - 1,result);

 }
/*每次在数字后面都会加上一个空格 " "，包括最后一个数字后也加上了空格，
这导致每一行输出(每一个排列）的末尾都有一个不可见的空格。
这个空格在逻辑上并不需要，但由于递归的方式，
每个数字后面统一加上空格以保持格式的一致性，所以最终结果里包含了这些多余的空格。*/

/*for instance : n = 2
1 2   // 注意“2”后面有一个不可见的空格
1 3   // 注意“3”后面有一个不可见的空格
...   // 其他组合，每一行末尾都有一个不可见的空格*/

} 

//wrapper function
void RollD6(int n) {
  vector<string> result;
  RollD6("",n,result);
  for(string s : result) {
    cout << s <<endl;
  }
  cout << result.size() <<endl;
}




// version that return noting
void printSubset(string sofar,string rest) {
  if(rest.empty()) {
    print_set(sofar);
    return;
  }
  char c = rest[0];
  string Newrest = rest.substr(1);

  printSubset(sofar,Newrest);
  printSubset(sofar + c,Newrest);

}

void printSubset(string s){
  printSubset("",s);
}

// version that return nothing and use pass-by-reference
void printSubset(vector<char>& sofar,vector<char>& rest,int k) {
if(k == rest.size()){
  print_set(sofar);
  return;
}
char thisone = rest[k];
printSubset(sofar,rest,k + 1);

//choose
sofar.push_back(thisone);
printSubset(sofar,rest,k + 1);
//unchoose
sofar.pop_back();
}

void printSubset(vector<char>& v){
  vector<char> sofar = {};
  printSubset(sofar,v,0);
}




//version that print the number of the subsets

int printSubset_(string sofar,string rest)
{
  if(rest.empty()) {
     print_set(sofar);
     return 1;
  }
  char c = rest[0];
  string NewRest = rest.substr(1);
  return printSubset_(sofar,NewRest) + printSubset_(sofar + c,NewRest);
}

int printSubset_(string s){
  return printSubset_("",s);
}

//version that print the number of thwe subsets and pass-by-reference
int printSubset_(vector<char>& sofar,vector<char>& rest,int k){
if(k == rest.size()) {
     print_set(sofar);
     return 1;
  }
  char c = rest[k];
  int num1 = printSubset_(sofar,rest,k + 1); 

  sofar.push_back(c);
  int num2 = printSubset_(sofar,rest,k + 1);
  sofar.pop_back();
  
  return num1 + num2;
}

int printSubset_(vector<char>& v){
  vector<char> sofar = {};
  return printSubset_(sofar,v,0);
}



//patition
bool ispartitionable(vector<int> &v,int sum1, int sum2) { 
    if(v.empty()) {
      return sum1 == sum2;
    }
    int thisone = v[v.size() - 1];
    v.pop_back();

    //choose
    //这样就可以遍历所有情况，有点像枚举法，2的n次方种可能
    bool result =  ispartitionable(v,sum1 + thisone,sum2) || ispartitionable(v,sum1,sum2 + thisone);

    //unchoose
    v.push_back(thisone);
    return result;
}

bool ispartitionable(vector<int> &v){
  return ispartitionable(v,0,0);
}


//partition2

bool ispartitionable2(vector<int> &v,vector<int> &v1,vector<int> &v2){
  if(v.empty()) {
    int sum1 = sum_vector(v1);
    int sum2 = sum_vector(v2);
    if(sum1 == sum2) {
      cout << "v1:";
      print_vector(v1);
      cout << "v2:";
      print_vector(v2);
    }
    return sum1 == sum2;
  }
  int thisone = v[v.size() - 1];
  v.pop_back();

  v1.push_back(thisone);
  bool result1 = ispartitionable2(v,v1,v2);
  //v1.erase(v.end() - 1);
  v1.pop_back();


  //Allow for early termination! if we have found a solution,we need not keep exploring
  
  if(result1){
  //do not forget to unchoose "thisone". Because we should not destroy the input
    v.push_back(thisone);

    return true;
  }

  v2.push_back(thisone);
  bool result2 = ispartitionable2(v,v1,v2);
  //v2.erase(v.end() - 1);
  v2.pop_back();
  
  v.push_back(thisone);
  return  result2;
}

bool ispartitionable2(vector<int> &v){
  vector<int> v1,v2;
  return ispartitionable2(v,v1,v2);
}




int main() {
  // coinflip(3);
  //   cout<<isPalindrome("abcba")<<endl;
  //   cout<<isPalindrome("efuh") <<endl;
  // vector<int> test = {1,2,3,4,5,8,10,39,40,89};
  // cout<<binaryFind(test,39)<<endl;
  //permute2("act");
  // RollD6(2);

  // cout << printSubset_("abd") <<endl;

  vector<int> test = {1,1,2,3};
  vector<int> test2 = {1,4,5,8};
  cout << ispartitionable2(test) <<endl;
  cout << ispartitionable2(test2) <<endl;

  // vector<char> v = {'a','b','c'};
  // cout << printSubset_(v) << endl;



  return 0;
}