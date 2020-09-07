#pragma once

inline int main()
{

	cout << "Harf Giriniz" << endl;
	const int boyut = 200;
	char ch[boyut];
	int sayacA = 0, sayacE = 0, sayacO = 0, sayacU = 0, sayacI = 0, sayacÝ = 0, sayacÜ = 0, sayacÖ = 0;
	getline(cin, ch);
	do
	{
		for (int i = 0; i < boyut; i++)
		{
			cin >> ch;
			if (ch[i] == 'a' || ch[i] == 'A')
			{
				sayacA++;
			}
			if (ch[i] == 'e' || ch[i] == 'E')
			{
				sayacE++;
			}
			if (ch[i] == 'ý' || ch[i] == 'I')
			{
				sayacI++;
			}
			if (ch[i] == 'i' || ch[i] == 'Ý')
			{
				sayacÝ++;
			}
			if (ch[i] == 'O' || ch[i] == 'O')
			{
				sayacO++;
			}
			if (ch[i] == 'ö' || ch[i] == 'Ö')
			{
				sayacÖ++;
			}
			if (ch[i] == 'u' || ch[i] == 'U')
			{
				sayacU++;
			}
			if (ch[i] == 'ü' || ch[i] == 'Ü')
			{
				sayacÜ++;
			}
			/*if (ch[i] == '\r')
			{
			break;
			}*/
			cout << sayacA << endl;
		}

	} while (ch[boyut] == 'r');
	system("pause");
	return 0;


}

int main();
