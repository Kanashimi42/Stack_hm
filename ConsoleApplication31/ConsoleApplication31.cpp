#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class Stack
{
	enum { EMPTY = -1, FULL = 100 };
	char st[FULL + 1];
	int top;

public:
	Stack();
	void Push(char c);
	char Pop();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	char GetLast();
};

Stack::Stack()
{
	top = EMPTY;
}

void Stack::Push(char c)
{
	if (!IsFull())
		st[++top] = c;
}

char Stack::Pop()
{
	if (!IsEmpty())
		return st[top--];
	else
		return 0;
}

bool Stack::IsEmpty()
{
	return top == EMPTY;
}

bool Stack::IsFull()
{
	return top == FULL;
}

int Stack::GetCount()
{
	return top + 1;
}

char Stack::GetLast()
{
	if (!IsEmpty())
		return st[top];
	else
		return 0;
}

bool CheckBrackets(const char* str)
{
	Stack stack;
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		char current = str[i];

		if (current == '(' || current == '{' || current == '[')
		{
			stack.Push(current);
		}
		else if (current == ')' || current == '}' || current == ']')
		{
			if (stack.IsEmpty())
				return false;

			char last = stack.GetLast();

			if ((current == ')' && last != '(') ||
				(current == '}' && last != '{') ||
				(current == ']' && last != '['))
			{
				return false;
			}

			stack.Pop();
		}
	}

	return stack.IsEmpty();
}

int main()
{
	char input[100];
	cout << "Enter a string with brackets (use '.' as the end marker): ";
	cin.getline(input, 100, '.');

	if (CheckBrackets(input))
	{
		cout << "The brackets are right." << endl;
	}
	else
	{
		cout << "The brackets are wrong." << endl;
	}

	return 0;
}
