#include<iostream>
#include<stack>
using namespace std;
  
// Standart Bir Ýkili Agaç Yapýsý
struct Dugum
{
    int data;
    struct Dugum *sol, *sag;
};
  
// Yeni düðümler yaratma
Dugum *newDugum(int mydeger)
{
    Dugum *t = new Dugum;
    t->data = mydeger;
    t->sol = t->sag = NULL;
    return t;
}
  
// Verilen iki aðaçta ortak düðümleri bulma
int ortakdugumler(Dugum *kok1, Dugum *kok2)
{
    // Inorder yapýsý baz alýnarak iki aðacýn nodelerinin iki ayrý yýðýn yapýsýna kaydedilmesi
    stack<Dugum *> stack1, s1, s2;
  
    while (1)
    {
        // Ýlk aðacýn nodelerinin s1 yýðýnýna push edilmesi
        if (kok1)
        {
            s1.push(kok1);
            kok1 = kok1->sol;
        }
  
        // Ýkinci aðacýn nodelerinin s2 yýðýnýna push edilmesi
        else if (kok2)
        {
            s2.push(kok2);
            kok2 = kok2->sol;
        }
  
        // Ýki kök de(kök1 ve kök2) burada NULL durumda 
        else if (!s1.empty() && !s2.empty())
        {
            kok1 = s1.top();
            kok2 = s2.top();
  
            // Ýki aðaçtaki mevcut veriler aynýysa
                        
            if (kok1->data == kok2->data){
					
                cout << kok1->data << " ";
                s1.pop();
                s2.pop();
                  
                kok1 = kok1->sag;
                kok2 = kok2->sag;
                return 1;
            }
  
            else if (kok1->data < kok2->data)
            {
                /*Ýlk aðacýn düðümü ikinci aðacýn düðümünden daha küçükse, 
				mevcut düðümün inorder sýralamada ikinci aðaç düðümününki ile ayný deðere sahip olabileceði açýktýr. 
				Böylece s2'den çýkýyoruz.*/
                s1.pop();
                kok1 = kok1->sag;
  
                // 1. aðacýn düðümlerine ihtiyaç duyduðumuzdan dolayý kok2'ye NULL deðer atandý.
                kok2 = NULL;
            }
            else if (kok1->data > kok2->data)
            {
                s2.pop();
                kok2 = kok2->sag;
                kok1 = NULL;
                
            }
        }
  
        // Her iki kök ve her iki yýðýn da boþ
        else  break;
    }
}
  
//Inorder sýralama yapmayý saðlama
void inorder(struct Dugum *kok)
{
    if (kok)
    {
        inorder(kok->sol);
        cout<<kok->data<<" ";
        inorder(kok->sag);
    }
}
  
//BST'de verilen verilerle yeni bir düðüm ekleme
struct Dugum* insert(struct Dugum* node, int data)
{
    //Aðaç boþsa, yeni bir düðüm döndür 
    if (node == NULL) return newDugum(data);
  
    // deðil ise aðacý tekrarla
    if (data < node->data)
        node->sol  = insert(node->sol, data);
    else if (data > node->data)
        node->sag = insert(node->sag, data);
  
    //Dugum pointerini(deðiþmemiþ) döndür
    return node;
}
  

int main()
{
    // Ýlk aðacý oluþturma
    Dugum *kok1 = NULL;
    kok1 = insert(kok1, 52);
    kok1 = insert(kok1, 13);
    kok1 = insert(kok1, 16);
    kok1 = insert(kok1, 30);
    kok1 = insert(kok1, 71);
    kok1 = insert(kok1, 87);
    kok1 = insert(kok1, 28);
  
    // 2. aðacý oluþturma
    Dugum *kok2 = NULL;
    kok2 = insert(kok2, 12);
    kok2 = insert(kok2, 77);
    kok2 = insert(kok2, 29);
    kok2 = insert(kok2, 74);
    kok2 = insert(kok2, 10);
  
    cout << "1.AGAC : ";
    inorder(kok1);
    cout << endl;
  
    cout << "2. AGAC : ";
    inorder(kok2);
  
    
   if(ortakdugumler(kok1, kok2)==1){
    	
		cout << "\nTRUE";}
		
	else {
		cout<< "\nFALSE";}	
    return 0;
}
