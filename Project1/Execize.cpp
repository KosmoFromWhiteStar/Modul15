#include <iostream>
#include <vector>
int corrector()
{
	std::string temp;
	std::cin >> temp;

	int result = 0;
	bool minus = temp[0] == '-';

	for (int t = (minus? 1 : 0); t < temp.length(); t++)
	{
		if (temp[t] < '0' || temp[t] > '9') std::cerr << "Invalid num";
		else
		{ 
			result *= 10;
			result += temp[t] - '0';
		}

	}
	if (minus) result *= -1;
	return result;

}

void print_vec (std::vector <int> vec)
{
	std::cout << "Vec: ";
	for (int o = 0; o < vec.size(); o++) {
		std::cout << vec[o] << " ";
	}
}

void ex_1()
{
	std::cout << "Exercise 1\n";

	std::vector <int> arr { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int i, j, summ = 0, max = 0, frst, snd=0, tmp = 0;

	for (i = 0; i < arr.size(); i++)
	{
		for (j = i; j < arr.size(); j++)
		{
			if (summ < tmp) snd = i;
			summ += arr[j];
		    tmp = summ;
		}
		if (max < summ)
		{
			frst = i;
			max = summ;
		}
		summ = 0;
	}	
	std::cout << "Result \n";
	std::cout << frst << " " << snd;

	for (int i = frst; i <= snd; i++) summ += arr[i];
	std::cout << "summ: " << summ;
}

void ex_2()
{
	std::cout << "Exercise 2!\n";
	std::vector <int> arr { 2, 10, 11, 15, 7 };
	int num = 9;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int y = i; y < arr.size(); y++)
		{
			if (arr[i] + arr[y] == num)
			{
				std::cout << arr[i] << " " << arr[y];
				break;
			}
		}

	}

	
}

void ex_3()
{
	std::vector <int> arr;
	int temp;
	std::cout << "Exercise 3\n";
	while (true)
	{
		std::cout << "Input: ";
		temp = corrector(); // cheked num on num
		if (temp == -1)
		{
			for (int i = 0; i < arr.size(); i++)
			{
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl;
		}
		else if (temp == -2) break;
		else arr.push_back(temp);
		for (int i = 0; i < arr.size() - 1; i++)
		{
			for (int c = i; c < arr.size(); c++) if (arr[i] > arr[c]) std::swap(arr[i], arr[c]);
		}
	}
}

void ex_4()
{
	std::vector <int> arr = { -100,-50, -5, 1, 10, 15 };

	for (int i = 0; i < arr.size() - 1; i++)
		{
			for (int c = i; c < arr.size(); c++)
				if (std::abs(arr[i]) > std::abs(arr[c])) std::swap(arr[i], arr[c]);
		}
	print_vec(arr);
}


int main()
{
	int choose = 0;
	std::cout << "Modul 15 HW.\nChoose exe (1-4):";
	choose = corrector();
	if (choose == 1) ex_1();
	else if (choose == 2) ex_2();
	else if (choose == 3) ex_3();
	else if (choose == 4) ex_4();

	return 0;
}
