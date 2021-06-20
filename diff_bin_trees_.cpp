#include<iostream>
#include<stack>
using namespace std;
  
// Standart Bir İkili Agaç Yapısı
struct Dugum
{
    int data;
    struct Dugum *sol, *sag;
};
  
// Yeni düğümler yaratma
Dugum *newDugum(int mydeger)
{
    Dugum *t = new Dugum;
    t->data = mydeger;
    t->sol = t->sag = NULL;
    return t;
}
  
// Verilen iki ağaçta ortak düğümleri bulma
int ortakdugumler(Dugum *kok1, Dugum *kok2)
{
    // Inorder yapısı baz alınarak iki ağacın nodelerinin iki ayrı yığın yapısına kaydedilmesi
    stack<Dugum *> stack1, s1, s2;
  
    while (1)
    {
        // İlk ağacın nodelerinin s1 yığınına push edilmesi
        if (kok1)
        {
            s1.push(kok1);
            kok1 = kok1->sol;
        }
  
        // İkinci ağacın nodelerinin s2 yığınına push edilmesi
        else if (kok2)
        {
            s2.push(kok2);
            kok2 = kok2->sol;
        }
  
        // İki kök de(kök1 ve kök2) burada NULL durumda 
        else if (!s1.empty() && !s2.empty())
        {
            kok1 = s1.top();
            kok2 = s2.top();
  
            // İki ağaçtaki mevcut veriler aynıysa
                        
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
                /*İlk ağacın düğümü ikinci ağacın düğümünden daha küçükse, 
				mevcut düğümün inorder sıralamada ikinci ağaç düğümününki ile aynı değere sahip olabileceği açıktır. 
				Böylece s2'den çıkıyoruz.*/
                s1.pop();
                kok1 = kok1->sag;
  
                // 1. ağacın düğümlerine ihtiyaç duyduğumuzdan dolayı kok2'ye NULL değer atandı.
                kok2 = NULL;
            }
            else if (kok1->data > kok2->data)
            {
                s2.pop();
                kok2 = kok2->sag;
                kok1 = NULL;
                
            }
        }
  
        // Her iki kök ve her iki yığın da boş
        else  break;
    }
}
  
//Inorder sıralama yapmayı sağlama
void inorder(struct Dugum *kok)
{
    if (kok)
    {
        inorder(kok->sol);
        cout<<kok->data<<" ";
        inorder(kok->sag);
    }
}
  
//BST'de verilen verilerle yeni bir düğüm ekleme
struct Dugum* insert(struct Dugum* node, int data)
{
    //Ağaç boşsa, yeni bir düğüm döndür 
    if (node == NULL) return newDugum(data);
  
    // değil ise ağacı tekrarla
    if (data < node->data)
        node->sol  = insert(node->sol, data);
    else if (data > node->data)
        node->sag = insert(node->sag, data);
  
    //Dugum pointerini(değişmemiş) döndür
    return node;
}
  

int main()
{
    // İlk ağacı oluşturma
    Dugum *kok1 = NULL;
    kok1 = insert(kok1, 52);
    kok1 = insert(kok1, 13);
    kok1 = insert(kok1, 16);
    kok1 = insert(kok1, 30);
    kok1 = insert(kok1, 71);
    kok1 = insert(kok1, 87);
    kok1 = insert(kok1, 28);
  
    // 2. ağacı oluşturma
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
