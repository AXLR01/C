#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	unsigned int w = 192, x = 168, y = 129, z = 10, adresse = 0, adresse_reseau = 0, adresse_broadcast; /* variables pour la gestion d adresse */
	unsigned long long int IPv4MaskLenght = pow(2, 32) - 1, notmask; /* variables pour masque */
	int n = 24, i; /*compteurs*/



	for (i = 0; i < (32 - n); i++)/* on calcule le mask au début il vaut (2^32)-1 soit 32 1 et on enleve les 8 premieres puissances de 2 pour avoir un binaire
								  = a 24 1 suivi de 8 0 qui correspond au octet 255.255.255.0 */
	{
		IPv4MaskLenght -= pow(2, i);
	}
	notmask = ~IPv4MaskLenght;//L inverse du mask pour calculer l'adresse broadcoast


	adresse = w; // On met dans l adresse dans les variables x,y,z,w
	adresse <<= 8;
	adresse += x;
	adresse <<= 8;
	adresse += y;
	adresse <<= 8;
	adresse += z;

	w = adresse;/*On trie pour recuperer les "octets" pour afficher les adresses*/
	w >>= 24;

	x = adresse;
	x >>= 16;
	x -= w * pow(2, 8);


	y = adresse;
	y >>= 8;
	y -= (w * pow(2, 16) + x * pow(2, 8));

	z = adresse;
	z -= (w * pow(2, 24) + x * pow(2, 16) + y * pow(2, 8));
	printf("Adresse machine : %u.%u.%u.%u\n", w, x, y, z); /* affichage adresse machine */

	adresse_reseau = (adresse) & (IPv4MaskLenght); /* affectation adresse reseau */
	w = adresse_reseau; /* stockage de l adresse" reseau dans les variables w,x,y,z */
	w >>= 24;

	x = adresse_reseau;
	x <<= 8;
	x >>= 24;

	y = adresse_reseau;
	y <<= 16;
	y >>= 24;

	z = adresse_reseau;
	z <<= 24;
	z >>= 24;

	printf("Adresse reseau : %u.%u.%u.%u\n", w, x, y, z); /* affichage adresse reseau */

	adresse_broadcast = adresse_reseau | notmask; /* affectation adresse broadcast */
	w = adresse_broadcast;/* stockage de l adresse" reseau dans les variables w,x,y,z */
	w >>= 24;

	x = adresse_broadcast;
	x <<= 8;
	x >>= 24;

	y = adresse_broadcast;
	y <<= 16;
	y >>= 24;

	z = adresse_broadcast;
	z <<= 24;
	z >>= 24;

	printf("Adresse broadcoast : %u.%u.%u.%u", w, x, y, z); /* affichage adresse broadcast */

	return 0;
}