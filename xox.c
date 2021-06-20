//27.05.2021 Furkan Karakoc
#include <stdio.h>

char izgara(int i) {
    switch(i) {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}

void ciz(int b[9]) {
    printf(" %c | %c | %c\n",izgara(b[0]),izgara(b[1]),izgara(b[2]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",izgara(b[3]),izgara(b[4]),izgara(b[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",izgara(b[6]),izgara(b[7]),izgara(b[8]));
}

int kazanma(const int board[9]) { //Oyuncunun kazanip kazanamadigi kontrol edilir, aksi durumlarda 0 donulur    

    unsigned kazanma_sartlari[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    
    for(i = 0; i < 8; ++i) {
    	if(board[kazanma_sartlari[i][0]] != 0 && board[kazanma_sartlari[i][0]] == board[kazanma_sartlari[i][1]] && board[kazanma_sartlari[i][0]] == board[kazanma_sartlari[i][2]])
            
			return board[kazanma_sartlari[i][2]];}
    
	return 0;}

int minimax(int board[9], int oyuncu) { //Oyuncunun pozisyonuna bakilir
    int kazanan = kazanma(board);
    if(kazanan != 0) return kazanan*oyuncu;

    int hamle = -1;
    int puan = -2;//Kaybetmeyi hamle yapmamaya tercih et
    int i;
    for(i = 0; i < 9; ++i) {//Tum hamleleri kontrol et ve eger uygunsa,hamleyi dene
        if(board[i] == 0) {
            board[i] = oyuncu;
            int thisPuan = -minimax(board, oyuncu*-1);
            if(thisPuan > puan) {
                puan = thisPuan;
                hamle = i;
            }//Rakip icin en kotu hamle secilir
            board[i] = 0;}//Denemeden sonra board sifirlanir
			}
    if(hamle == -1) return 0;
    
    return puan;}

void bilgisayar_hareketi(int board[9]) {
    int hamle = -1;
    int puan = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = 1;
            int gecici_puan = -minimax(board, -1);
            board[i] = 0;
            if(gecici_puan > puan) {
                puan = gecici_puan;
                hamle = i;}
				}
    	}
    
    board[hamle] = 1;} //Belirli bir düðümdeki minimax aðacýna dayalý bir puan döndürür


void oyuncu_hareketi(int board[9]) {
	int hamle = 0;
	do {
		kare:
		
		printf("\n0 ile 8 Arasinda Bir Kare Secin: ");
		scanf("%d", &hamle);
		
		if(board[hamle] != 0) {
			printf("Bu Kare Dolu !");
			goto kare;}
			
		printf("\n");} 
		
	while (hamle >= 9 || hamle < 0 && board[hamle] == 0);
		board[hamle] = -1;}

int main() {
    int board[9] = {0,0,0,0,0,0,0,0,0};    
    printf("\nBILGISAYAR: O    SEN: X \n\nHANGI OYUNCU OLMAK ISTERSIN ? (1)/(2) "); //Bilgisayarýn karelerine 1, oyuncunun karelerine -1
    int oyuncu=0;
    scanf("%d",&oyuncu);
    printf("\n");
    unsigned sira;
    for(sira = 0; sira < 9 && kazanma(board) == 0; ++sira) {
        if((sira+oyuncu) % 2 == 0)	bilgisayar_hareketi(board);
        else {
            ciz(board);
            oyuncu_hareketi(board);}
    }
    
    switch(kazanma(board)) {
    	
        case 0:
            printf("BERABERE!\n");
            break;
            
        case 1:
            ciz(board);
            printf("KAYBETTIN!\n");
            break;
            
        case -1:
            printf("KAZANDIN!\n");
            break;
    }
}
