// hash map resolving with chaining
#include <bits/stdc++.h> 
using namespace std;

class HashMap {
public:
int capacity = 5;
list<int> * hash_table = new list<int> [capacity];

void Insert(int data) {
	int hash_idx = data%capacity;
if(hash_table[hash_idx].empty()) {
		list<int> slot_list;
		slot_list.push_back(data);
		hash_table[hash_idx] = slot_list;
	}
	else {
		hash_table[hash_idx].push_back(data);
	}
	return;
}

void Display() {
	for(int idx = 0;idx<capacity;idx++) {
		for(int &data : hash_table[idx]) {
			cout<<data<<" --> ";
		}
		cout<<endl;
	}
	return;
}

bool Search(int &data) {
	for(int idx = 0;idx<capacity;idx++) {
		for(int &hash_data : hash_table[idx]) {
			if(hash_data==data) {
				return true;
			}
		}
	}
	return false;
}

void Remove(int &data) {
	for(int idx = 0;idx<capacity;idx++) {
		for(auto itr = hash_table[idx].begin();itr!=hash_table[idx].end();itr++) {
			if(*itr==data) {
				hash_table[idx].erase(itr);
			}
		}
	}
	return;
}
};

int main() {
HashMap hash_mp;
int num_val; 
cin>>num_val;
for(int idx = 0;idx<num_val;idx++) {
	int data;
	cin>>data;
	hash_mp.Insert(data);
}
hash_mp.Display();
return (3);
}
