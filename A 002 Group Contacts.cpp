//Given contact info, a name associated with a list of emails
//group contacts, identity uniquely determined by associated emails. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Contact {
public:
	string name;
	vector<string> emails;
};

class UnionFind
{
public:

	UnionFind(int n)
	{
		parents.resize(n);
		for (int i = 0; i < n; ++i) parents[i] = i;
	}

	int Find(int x)
	{
		if (parents[x] == x) return x;
		parents[x] = Find(parents[x]);
		return parents[x];
	}

	void Union(int x, int y)
	{
		int xparent = Find(x);
		int yparent = Find(y);
		if (xparent == yparent) return;
		parents[xparent] = yparent;
	}

	int parent(int x)
	{
		return parents[x];
	}

private:
	vector<int> parents;
};

vector<vector<Contact>> group_contacts(vector<Contact>& input) { 
	unordered_map<string, int> Emails; int count = 0;

	//get all unique email and code it to a number;
	for (auto cont : input)
	{
		for (auto email : cont.emails)
		{
			if (Emails.count(email) == 0)
			{
				Emails[email] = count++;
			}
		}
	}
	UnionFind U(count);
	//do a union of all the emails -- > get groups
	for (auto cont : input)
	{
		for (int i = 1; i < cont.emails.size(); ++i)
		{
			U.Union(Emails[cont.emails[i]], Emails[cont.emails[i - 1]]);
		}
	}

	//get output
	for (int i = 0; i < count; ++i) { U.Find(i); } // all point to group. 
	unordered_map<int, vector<Contact>> ret;
	for (auto cont : input)
	{
		ret[U.parent(Emails[cont.emails.front()])].push_back(cont);
	}
	vector<vector<Contact>> result;
	int n = ret.size();
	result.resize(n);
	int index = 0;
	for (auto pir : ret)
	{
		result[index++] = pir.second;
	}
	return result;
}

int main()
{
	vector<Contact> input;
	Contact cont1 = { "John", { "john@gmail.com" } };
	Contact cont2 = { "Mary", { "mary@gmail.com" } };
	Contact cont3 = { "John", { "john@yahoo.com" } };
	Contact cont4 = { "John", { "john@gmail.com", "john@yahoo.com", "john@hotmail.com" } };
	Contact cont5 = { "Bob", { "bob@gmail.com" } };
	Contact cont6 = { "Bob", { "bob@gmail.com", "bob@hotmail.com" } };
	Contact cont7 = { "John E", { "john@gmail.com" } };
	input.push_back(cont1); input.push_back(cont2); input.push_back(cont3); input.push_back(cont4); input.push_back(cont5); input.push_back(cont6); input.push_back(cont7);

	auto groups=group_contacts(input);
	for (auto group : groups)
	{
		cout << "----" << endl;
		for (auto contact : group)
		{
			cout << contact.name << ": " << endl;
			for (auto email : contact.emails) cout << email << " ";
			cout << endl;
		}
	}
}
