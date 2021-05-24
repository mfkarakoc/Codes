#include<iostream>
#include<stack>
using namespace std;
  
// Standart Bir �kili Aga� Yap�s�
struct Dugum
{
    int data;
    struct Dugum *sol, *sag;
};
  
// Yeni d���mler yaratma
Dugum *newDugum(int mydeger)
{
    Dugum *t = new Dugum;
    t->data = mydeger;
    t->sol = t->sag = NULL;
    return t;
}
  
// Verilen iki a�a�ta ortak d���mleri bulma
int ortakdugumler(Dugum *kok1, Dugum *kok2)
{
    // Inorder yap�s� baz al�narak iki a�ac�n nodelerinin iki ayr� y���n yap�s�na kaydedilmesi
    stack<Dugum *> stack1, s1, s2;
  
    while (1)
    {
        // �lk a�ac�n nodelerinin s1 y���n�na push edilmesi
        if (kok1)
        {
            s1.push(kok1);
            kok1 = kok1->sol;
        }
  
        // �kinci a�ac�n nodelerinin s2 y���n�na push edilmesi
        else if (kok2)
        {
            s2.push(kok2);
            kok2 = kok2->sol;
        }
  
        // �ki k�k de(k�k1 ve k�k2) burada NULL durumda 
        else if (!s1.empty() && !s2.empty())
        {
            kok1 = s1.top();
            kok2 = s2.top();
  
            // �ki a�a�taki mevcut veriler ayn�ysa
                        
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
                /*�lk a�ac�n d���m� ikinci a�ac�n d���m�nden daha k���kse, 
				mevcut d���m�n inorder s�ralamada ikinci a�a� d���m�n�nki ile ayn� de�ere sahip olabilece�i a��kt�r. 
				B�ylece s2'den ��k�yoruz.*/
                s1.pop();
                kok1 = kok1->sag;
  
                // 1. a�ac�n d���mlerine ihtiya� duydu�umuzdan dolay� kok2'ye NULL de�er atand�.
                kok2 = NULL;
            }
            else if (kok1->data > kok2->data)
            {
                s2.pop();
                kok2 = kok2->sag;
                kok1 = NULL;
                
            }
        }
  
        // Her iki k�k ve her iki y���n da bo�
        else  break;
    }
}
  
//Inorder s�ralama yapmay� sa�lama
void inorder(struct Dugum *kok)
{
    if (kok)
    {
        inorder(kok->sol);
        cout<<kok->data<<" ";
        inorder(kok->sag);
    }
}
  
//BST'de verilen verilerle yeni bir d���m ekleme
struct Dugum* insert(struct Dugum* node, int data)
{
    //A�a� bo�sa, yeni bir d���m d�nd�r 
    if (node == NULL) return newDugum(data);
  
    // de�il ise a�ac� tekrarla
    if (data < node->data)
        node->sol  = insert(node->sol, data);
    else if (data > node->data)
        node->sag = insert(node->sag, data);
  
    //Dugum pointerini(de�i�memi�) d�nd�r
    return node;
}
  

int main()
{
    // �lk a�ac� olu�turma
    Dugum *kok1 = NULL;
    kok1 = insert(kok1, 52);
    kok1 = insert(kok1, 13);
    kok1 = insert(kok1, 16);
    kok1 = insert(kok1, 30);
    kok1 = insert(kok1, 71);
    kok1 = insert(kok1, 87);
    kok1 = insert(kok1, 28);
  
    // 2. a�ac� olu�turma
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
