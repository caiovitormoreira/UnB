#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <windows.h>

using namespace std;
//cabeçalho de funções.
vector<string> MakeVectorFromTxt (string dutytxt);
void ProtocolPrinter (string dutytxt);
void ProtocolInfo (int info);
void menu ();
void menuanalise(string dutytxt);
void totalsize (string dutytxt);
void stats(string dutytxt);
void duration (string dutytxt);
void ipversion (string dutytxt);
void iplist (string dutytxt);
void txtcheck (string dutytxt);
void analisetxt ();
void cadastroip();
void menucadastro();
void printIP();
void menuIPs();
void recognizeip(string dutytxt);
void iplookup(string dutytxt);
void IPdiscovery();


string masterdutytxt; 


int main()
{
	setlocale(LC_ALL, "Portuguese");
	menu();
	return 0;
		
}

void menu (){
	int optionmenu;
	cout <<"WIRESHARK NETWORK SIMPLE ANALYSER C++ TOOL KIT v1.0";
	cout <<"\n\nMENU";
	cout <<"\n<1> Analisar capturas do wireshark";
	cout <<"\n<2> Cadastro de IPs";
	cout <<"\n\n<0> Para sair\n";
	do{
		cin >> optionmenu;
		if (optionmenu==1){ analisetxt();}
		if (optionmenu==2){ menucadastro();}
		if (optionmenu==0){ system("CLS"); exit(0);}
		else cout <<"Opção inválida...";
	} while (optionmenu>2);
	 
}

vector<string> MakeVectorFromTxt (string dutytxt){
	vector<string> vector1;	
	string nametxt;
	nametxt = dutytxt+".txt";
	ifstream myfile(nametxt.c_str());
	
	copy(istream_iterator<string>(myfile),
	istream_iterator<string>(),
	back_inserter(vector1));
	return vector1;	 
}

void ProtocolPrinter (string dutytxt){
	int rtmpcont=0, sslcont=0, dnscont=0, arpcont=0, tcpcont=0;
	int httpcont=0, udpcont=0, tlscont=0, icmpcont=0, icmpv6cont=0, elsecont=0;
	
	cout <<"Loading...";
	vector<string> vector3 = MakeVectorFromTxt (dutytxt);
	vector<string>::iterator it3 = vector3.begin();
	cout <<"\r\t\t";
	cout <<"### PROTOCOLOS ###"<<endl<<endl;
	
	for (it3; it3 != vector3.end(); ++it3)
	{
		if (*it3 == "Protocol")
		{
			++it3;
			if ((*it3) == "Length")
			{
				it3=it3+6;
				if ((*it3) == "TCP") tcpcont++;
				else if ((*it3) == "UDP") udpcont++;
				else if ((*it3) == "SSL") sslcont++;
				else if ((*it3) == "HTTP") httpcont++;
				else if ((*it3) == "TLSv1.2") tlscont++;
				else if ((*it3) == "ICMP") icmpcont++;
				else if ((*it3) == "ICMPv6") icmpv6cont++;
				else if ((*it3) == "ARP") arpcont++;				
				else if ((*it3) == "RTMP") rtmpcont++;
				else if ((*it3) == "DNS") dnscont++;
				else elsecont++;				
				it3=it3-6;
			}
			--it3;				
		}
	}
	
	cout << tcpcont << "\tprotocolos TCP"<<endl;
	cout << udpcont << "\tprotocolos UDP"<<endl;
	cout << sslcont << "\tprotocolos SSL"<<endl;
	cout << httpcont << "\tprotocolos HTTP"<<endl;
	cout << arpcont << "\tprotocolos ARP"<<endl;
	cout << rtmpcont << "\tprotocolos RTMP"<<endl;
	cout << dnscont << "\tprotocolos DNS"<<endl;
	cout << tlscont << "\tprotocolos TLSv1.2"<<endl;
	cout << icmpcont << "\tprotocolos ICMP"<<endl;
	cout << icmpv6cont << "\tprotocolos ICMPv6"<<endl;
	cout << elsecont << "\tOutros protocolos"<<endl;
}

void ProtocolInfo (int info){
	cout <<"\nSobre qual pacote deseja mais informacoes: ";
	cout<<"\n<1> TCP\n";
	cout<<"<2> UDP\n";
	cout<<"<3> SSL\n";
	cout<<"<4> HTTP\n";
	cout<<"<5> ARP\n";
	cout<<"<6> RTMP\n";
	cout<<"<7> DNS\n";
	cout<<"<8> TLSv1.2\n";
	cout<<"<9> ICMP\n";
	cout<<"<10> ICMPv6\n";
	cout<<"Ou pressione <0> para voltar ";
	int maisinfo;
	
	do{
	cin >> maisinfo;
	string url;
	if (maisinfo==1){
		url = "https://wiki.wireshark.org/Transmission_Control_Protocol?action=show&redirect=TCP";
	 	ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	 	cout <<"Webpage aberta!";
	}
	if (maisinfo==2){
		url = "https://wiki.wireshark.org/User_Datagram_Protocol?action=show&redirect=UDP";
	 	ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	 	cout <<"Webpage aberta!";
	}
	if (maisinfo==3){
		url = "https://wiki.wireshark.org/SSL";
	 	ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	 	cout <<"Webpage aberta!";
	}
	if (maisinfo==4){
		url = "https://wiki.wireshark.org/Hyper_Text_Transfer_Protocol?action=show&redirect=HTTP";
	 	ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	 	cout <<"Webpage aberta!";
	}
	if (maisinfo==5){
		url = "https://wiki.wireshark.org/AddressResolutionProtocol?action=show&redirect=ARP";
	 	ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	 	cout <<"Webpage aberta!";
	}
	if (maisinfo==6){
		url = "https://wiki.wireshark.org/RTMPT";
	 	ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	 	cout <<"Webpage aberta!";
	}
	if (maisinfo==7){
		url = "https://wiki.wireshark.org/DNS";
	 	ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	 	cout <<"Webpage aberta!";
	}
	if (maisinfo==8){
		url = "https://www.ietf.org/rfc/rfc5246.txt";
	 	ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	 	cout <<"Webpage aberta!";
	}
	if (maisinfo==9){
		url = "https://wiki.wireshark.org/Internet_Control_Message_Protocol";
	 	ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	 	cout <<"Webpage aberta!";
	}
	if (maisinfo==10){
		url = "https://wiki.wireshark.org/ICMPv6";
	 	ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	 	cout <<"Webpage aberta!";
	}	
	if (maisinfo>=11){ cout<< "opção invalida\n";
	}
	} while (maisinfo!=0);
	system("CLS");
	menuanalise(masterdutytxt);
	
}

void menuanalise(string dutytxt){
	system("CLS");
	txtcheck(dutytxt);
	cout <<endl<<endl;
	cout <<"<1> Obter estatisticas de trafego"<<endl;
	cout <<"<2> Fazer analise de protocolos utilizados"<<endl;
	cout <<"<3> Fazer analise de endereços IPs"<<endl;
	cout <<"<0> Voltar"<<endl;
	int optionanalise;
	do{
		cin >> optionanalise;
		if (optionanalise==1){
		system("CLS");
		stats (dutytxt);
		cout <<endl<<endl;
		system("pause");
		system("CLS");
		menuanalise(masterdutytxt);
		}
		if (optionanalise==2){
		system ("CLS");
		ProtocolPrinter (dutytxt);
		cout <<"\n<1> Caracteristicas de cada protocolo";
		cout <<"\n<0> Para voltar.\n";
		int info; 
		do{
			cin >> info;
			if (info==1) {
				system("CLS");
				ProtocolInfo(info);
			}
			if (info==0) {
				system("CLS");
				menuanalise(masterdutytxt);
			}
			else cout<<"Opção inválida. Tente novamente...";
		}while (info>1);
		}
		if (optionanalise==3){menuIPs();}
		if (optionanalise==0){
		system("CLS");
		menu();
	}
		else cout<<"Opção inválida. Tente novamente...";
	}while (optionanalise>3);
}

void totalsize (string dutytxt){
	cout <<"Loading...";
	vector<string> vector3 = MakeVectorFromTxt (dutytxt);
	vector<string>::iterator it3 = vector3.begin();
	cout <<"\r";
	int totalsize=0;
	
	for (it3; it3 != vector3.end(); ++it3)
	{
		if (*it3 == "Protocol")
		{
			++it3;
			if ((*it3) == "Length")
			{
				it3=it3+7;
				float number=0;
				istringstream(*it3) >> number;
				totalsize=totalsize+number;
				it3=it3-7;
			}
			--it3;				
		}
	}
	cout <<"Estatísticas: \n\n";
	if (totalsize<1024)	cout <<"Tamanho total em bytes: " <<totalsize;
	if ((totalsize > 1024)&&(totalsize<1048576)) cout <<"Tamanho total em KB: " <<totalsize/1024;
	if (totalsize>=1048576) cout <<"Tamanho total em MB: " <<totalsize/1048576;
	
}

void stats(string dutytxt){
	totalsize(dutytxt);
	duration(dutytxt);
	ipversion(dutytxt);
	}
	
void duration (string dutytxt){
	cout <<endl<<"Loading...";
	vector<string> vector3 = MakeVectorFromTxt (dutytxt);
	vector<string>::iterator it3 = vector3.begin();
	cout <<"\r";
	//cout << endl<<endl;
	float time=0;
	for (it3; it3 != vector3.end(); ++it3)
	{
		if (*it3 == "Time")
		{
			{
				it3=it3+7;
				istringstream(*it3) >> time;
				it3=it3-7;
			}			
		}
	}
	cout <<"Tempo total de captura: "<<time<<" segundos.";
}

void ipversion (string dutytxt){
	cout <<endl<<"Loading...";
	vector<string> vector3 = MakeVectorFromTxt (dutytxt);
	vector<string>::iterator it3 = vector3.begin();
	cout <<"\r";
	//cout << endl<<endl;
	float ipv4=0, ipv6=0;
	for (it3; it3 != vector3.end(); ++it3)
	{
		if (*it3 == "Protocol")
		{
			++it3;
			if ((*it3) == "Version")
			{
				++it3;
				float number=0;
				istringstream(*it3) >> number;
				if (number==4) ipv4++;
				if (number==6) ipv6++;				
				it3=it3-2;
			}		
		}
	}
	cout <<"Pacotes ipv4: "<<ipv4<<" ("<<(100*ipv4)/(ipv4+ipv6)<<"%)"<<endl;
	cout <<"Pacotes ipv6: "<<ipv6<<" ("<<(100*ipv6)/(ipv4+ipv6)<<"%)"<<endl;
}

void iplist (string dutytxt){	
	vector<string>vector1 = MakeVectorFromTxt (dutytxt);
	vector<string>::iterator it1 = vector1.begin();
	vector<string>vectorip;
	vector<string>::iterator itip = vectorip.begin();
		
	for (it1; it1 != vector1.end(); ++it1)
	{
		if (*it1 == "Destination")
		{
			++it1;
			if ((*it1) == "Protocol")
			{
				it1=it1+6;
				vectorip.push_back(*it1);
				it1=it1-6;
			}
			--it1;				
		}
	}
	//agora eu tenho o vectorip com todos os ips.
	itip = vectorip.begin();
	for (itip; itip != vectorip.end(); ++itip){
		cout <<*itip<<endl;
	}
	cout <<endl;
	system ("pause");
	menuIPs();
}

void txtcheck(string dutytxt){
	setlocale(LC_ALL,"");
	string nome;
	nome=dutytxt+".txt";
	ifstream meuarquivo(nome.c_str());
	if (meuarquivo.is_open())
	{ cout <<"Arquivo carregado com sucesso!";
	meuarquivo.close();
	}
	else {
		system ("CLS");
		cout <<"## Não foi possível abrir o aquivo! ##"<<endl<<endl;
		menu();
	}
}

void analisetxt(){
	string objecttxt, stringclear;
	getline (cin, stringclear);
	//esse getline serve para limpar um \n que vem do menu();
	cout <<"Digite o nome do arquivo de texto a ser analisado: ";
	getline (cin, objecttxt);
	masterdutytxt = objecttxt;
	menuanalise (objecttxt);	
}

void cadastroip(){
	string stringclear, nomeip, ip;
	getline (cin, stringclear);
	//esse primeiro getline serve para limpar um \n que vem do menu();
	cout <<"Digite um IP conhecido por voce: ";
	getline (cin, ip);
	cout <<"Digite o website para esse IP: ";
	getline (cin, nomeip);
	
	setlocale(LC_ALL,""); 
	ofstream meuarquivo("cadastroip.txt", ofstream::app);
	if (meuarquivo.is_open()){
		meuarquivo << "&& "<<ip <<endl;
		meuarquivo << nomeip<<endl;       
		meuarquivo.close();
		system("CLS");
		cout << "### IP cadastrado com sucesso! ###\n"<<endl<<endl<<endl;
		system("pause");
	}
	else
		cout << "Não foi possível abrir o arquivo\n";
	cout <<endl;
	menucadastro();
	}

void menucadastro(){
	system("CLS");
	cout <<"Menu de cadastro"<<endl<<endl;
	cout <<"<1> Cadastrar IPs conhecidos"<<endl;
	cout <<"<2> Verificar IPs cadastrados"<<endl;
	cout <<"<3> Apagar endereços IP cadastrados"<<endl;
	cout <<"<4> Descobrir IP"<<endl;
	cout <<"<0> Voltar"<<endl;
	int optionanalise;
	do{
	cin >> optionanalise;
	if (optionanalise==1){
		system("CLS");
		cadastroip();
		cout <<endl<<endl;
		system("pause");
		system("CLS");
		menucadastro();
	}
	if (optionanalise==2){
		system ("CLS");
		printIP();
		system("pause");
		menucadastro();
	}
	if (optionanalise==3){
		system("CLS");
		setlocale(LC_ALL,""); 
		ofstream meuarquivo("cadastroip.txt", ofstream::trunc);
		cout <<"Endereços apagados!!! \n\n";
		system ("pause");
		menucadastro();
	}
	if (optionanalise==4){
		system("CLS");
		IPdiscovery();
		menucadastro();
	}
	if (optionanalise==0){
		system("CLS");
		menu();
	}
	
	else cout <<"Opção invalida...";
	}while (optionanalise>4);
}

void printIP(){
	string stringclear, cadastroip ="cadastroip";
	getline (cin, stringclear);
	//esse primeiro getline serve para limpar um \n que vem do menu();
	vector<string> vector1 = MakeVectorFromTxt(cadastroip);
	vector<string>::iterator it1 = vector1.begin();
	
	for (it1; it1 != vector1.end(); ++it1){
		if (*it1 == "&&"){
			++it1; cout <<"IP: "<<*it1<<endl;
			++it1; cout <<"Website: "<<*it1<<endl<<endl;
			--it1;
		}
	}
}

void menuIPs(){
	string stringclear;
	getline (cin, stringclear);
	//só para limpar o \n que vem junto.
	system ("CLS");
	cout <<"\tANÁLISE DE IPs"<<endl<<endl;
	cout <<"<1> Listar todos os IPs que trocaram pacotes durante análise."<<endl;
	cout <<"<2> Obter dados de um IP específico. "<<endl;
	cout <<"<3> Reconhecer IPs cadastrados."<<endl<<endl;
	cout <<"<0> Voltar"<<endl;
	int optionmenuip;
	do{
		
		cin >>optionmenuip;
		if (optionmenuip ==1 ) {system ("CLS"); iplist(masterdutytxt);}
		if (optionmenuip ==2 ) {system("CLS"); iplookup(masterdutytxt);}
		if (optionmenuip ==3 ) {system("CLS"); recognizeip(masterdutytxt);}
		if (optionmenuip ==0 ){ menuanalise(masterdutytxt); }
		else cout <<"Opção inválida...";
		}while (optionmenuip>2);
}

void recognizeip(string dutytxt){

	string stringclear, cadastroip ="cadastroip";
	getline (cin, stringclear);
	//esse primeiro getline serve para limpar um \n que vem do menu();
	vector<string>vector1 = MakeVectorFromTxt (dutytxt);
	vector<string>::iterator it1 = vector1.begin();
	vector<string>vectorip;
	vector<string>::iterator itip = vectorip.begin();
	vector<string>vector2 = MakeVectorFromTxt (cadastroip);
	vector<string>::iterator it2 = vector2.begin();
	for (it1; it1 != vector1.end(); ++it1)
	{
		if (*it1 == "Destination")
		{
			++it1;
			if ((*it1) == "Protocol")
			{
				it1=it1+6;
				vectorip.push_back(*it1);
				it1=it1-6;
			}
			--it1;				
		}
	}
	//agora eu tenho o vectorip com todos os ips.
	//e vector2 com os IPs cadastrados
	it2 = vector2.begin();
	itip =vectorip.begin();
	int ocorrencia=0;
	
	for (itip; itip != vectorip.end(); ++itip){
		for (it2; it2 != vector2.end(); ++it2){
			if ((*it2)==(*itip)) {ocorrencia++;++it2;cout <<*it2<<endl;}
		}
		it2=vector2.begin();
	}
	if (ocorrencia==0) cout<<"Nenhuma ocorrencia de IPs conhecidos encontrada!"<<endl<<endl;
	system ("pause");
	menuanalise(masterdutytxt);		
} 

void iplookup(string dutytxt){
	string stringclear, iplookup;
	getline (cin, stringclear);
	//esse primeiro getline serve para limpar um \n que vem do menu();
	vector<string>vector1 = MakeVectorFromTxt (dutytxt);
	vector<string>::iterator it1 = vector1.begin();
	
	system ("CLS");
	cout <<"Digite um IP para fazer a busca desejada: ";
	getline (cin, iplookup);
	system ("CLS");
	cout <<"Informações sobre o IP "<<iplookup<<endl<<endl; 
	int ocorrencias=0, size=0, totalsize=0;	
	
	for (it1; it1 != vector1.end(); ++it1)
	{
		if (*it1 == "Destination")
		{
			++it1;
			if ((*it1) == "Protocol")
			{
				it1=it1+6;
				if (*it1==iplookup){
				ocorrencias++;
				it1=it1+2;
				istringstream(*it1) >> size;
				totalsize=totalsize+size;
				it1=it1-2;
				}
				it1=it1-6;
			}
			--it1;				
		}
	}
	cout <<"Numero de pacotes trocados com esse IP: "<<ocorrencias<<endl;
	cout <<"Tamanho total dos dados trocados: "<<totalsize<<" bytes"<<endl;
	cout <<"Pacotes utilizados na comunicação: "<<endl;
	
	it1 = vector1.begin();	
	for (it1; it1 != vector1.end(); ++it1)
	{
		if (*it1 == "Destination")
		{
			++it1;
			if ((*it1) == "Protocol")
			{
				it1=it1+6;
				if (*it1==iplookup){
				it1=it1+1;
				cout <<*it1<<endl;
				it1=it1-1;
				}
				it1=it1-6;
			}
			--it1;				
		}
	}
	system ("pause");
	menuanalise(masterdutytxt);		
}

void IPdiscovery(){
	string clear, ipclean, nomeip, ip="";
	getline (cin, clear);
	string IPdiscovery="IPdiscovery";
	cout << "Digite a URL do site\n";
	getline (cin,ip);
	string concatena;    
	concatena="ping "+ip +" > IPdiscovery.txt";
	cout << "Aguarde...\n";
	system(concatena.c_str());
	ifstream meuarquivo ("IPdiscovery.txt");
	vector<string> vector1 = MakeVectorFromTxt(IPdiscovery);
	vector<string>::iterator it1 = vector1.begin();
	
	if (*it1=="Disparando"){
		it1=it1+2;		
		ipclean=*it1;
		ipclean.erase(ipclean.begin());
		ipclean.erase(ipclean.end()-1);		
		cout <<endl<<"O endereço IP do website é: "<<ipclean<<endl;
	}
	else {cout <<"Nao foi possivel encontrar o endereço"<<endl<<endl;system("pause");system ("CLS");menucadastro();}
	
	int opcao=0;
	cout <<"Digite <1> se deseja cadastrar esse endereço de IP "<<endl;
	cout <<"Digite <0> para voltar ";
	cin >>opcao;
	do{
		if (opcao==1){
			setlocale(LC_ALL,""); 
			ofstream meuarquivo2("cadastroip.txt", ofstream::app);
			if (meuarquivo2.is_open()){
				meuarquivo2 << "&& "<<ipclean <<endl;
				meuarquivo2 << ip<<endl;       
				meuarquivo2.close();
				system("CLS");
				cout << "### IP cadastrado com sucesso! ###\n"<<endl<<endl<<endl;
				system("pause");
			}
			else
			cout << "Não foi possível abrir o arquivo\n";
		cout <<endl;
		}
		if (opcao==0) menucadastro();
	}while (opcao>1);
	menucadastro();
}



