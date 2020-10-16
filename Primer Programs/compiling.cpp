# include <stdio.h>
# include <conio.h>

float ct, pt, pu;
// pu = porcentaje de utilidad

int nf, na, nb, nc, ta, tb, tc, m2, pa, pb, pc;

main() {
	na = 5;
	nb = 3;
	nc = 2;
	
	pa = 10 * na;
	pb = 15 * nb;
	pc = 20 * nc;
	
	m2 = pa + pb + pc;
	
	printf("m2 de pl%cstico  -> %d\n", 160, m2);
	// Flotadores = na + nb + nc
	printf("flotadores      -> %d\n", (na + nb + nc));
	ta = na * 25;
	printf("tapas 1m $25    -> %d\n", na);
	tb = nb * 35;
	printf("tapas 1.5m $35  -> %d\n", nb);
	tc = nc * 45;
	printf("tapas 2m $45    -> %d\n", nc);
	
	ct = (m2*50) + ((na + nb + nc)*20)+ (ta + tb + tc);
	pt = (na * 760) + (nb*1130) + (nc*1490);
	pu = ((pt/ct) - 1)*100;
	
	printf("costo total     -> $%.2f\n", ct);
	printf("precio total    -> $%.2f\n", pt);
	printf("%c utilidad      -> %.2f%c\n",37, pu, 37);
	getche();
	
}


