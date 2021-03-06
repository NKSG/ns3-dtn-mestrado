#include <cmath>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>

#define PKTSIZE		512
#define NPKT		5
#define MAXMESG		1000
/* generates an exponential random variable given the mean in micro seconds*/
double ExpRnd(double mean) {
	double unif_rnd, exp_rnd;

	unif_rnd = (double) rand() / (double) RAND_MAX;

	exp_rnd = -mean * log(1 - unif_rnd);
	return (exp_rnd);
}

int calcDest(){
	//eturn 0;
	return rand()%2 + 1;
}

int calcFont(){
//	int a;
//	while(1){
//		a  = rand()%49+1;
//		if(a >= 0 && a <= 4) continue;
//		else break;
//	}
//	return a;
	return 0;//rand()%16 + 2;//rand()%4;
}

int main(int argc, char** argv) {
        int seed = (int)time(0);
        srand(seed);
	struct timeval *tp, tp1; /* used for getting timeofday */
	double elapsed_time = 0;
	char data[MAXMESG]; /* maximum size data packet */
	int pktsize = PKTSIZE; /* packet size */
	double rnd_mean = 5.0;
	double sleeptime = 0; /* sleep in us between 2 bulks */

	double avg_rate = 1.0;/*avg. rate (Mbps) to probe at */
	double duration = 500;/* time in seconds for which to probe at */

	rnd_mean = ((double) 6 * PKTSIZE/2) / avg_rate;
	tp = (struct timeval *) (malloc(sizeof(struct timeval)));

	(void) gettimeofday(&tp1, (struct timezone *) 0);

	(void) gettimeofday(tp, (struct timezone *) 0);

	double time = 0.0;

	int pktsend = 0;

	sleeptime = ExpRnd(rnd_mean);
	time += sleeptime;

	int i = 1;
	while ((time/1000.0) <= duration) {

		printf("%.2f C M%d %d %d %d u3\n", time/1000.0,i,calcFont(),calcDest(),pktsize);
		i++;
		sleeptime = ExpRnd(rnd_mean);
		time += sleeptime;

		/*
		printf("%.2f %.2f\n", elapsed_time, time);

		if (elapsed_time > time) {
			sleeptime = ExpRnd(rnd_mean);
			time += sleeptime;
			printf("%.2f %.2f C M1 7 8 256 u3\n", time/1000000.0, elapsed_time);
		}
		*/

		//smartwait((unsigned) (sleeptime - .5), &tp1);
		//(void) gettimeofday(&tp1, (struct timezone *) 0);
		/* Wait for smartwait-1+0.5
		 The -1 is to account for gettimeofday, the +0.5 is for rounding*/

		//udprecord->num = htonl((u_long) (pktsend + 1));

		//5.0     C       M1      2       0       256     u3

		/* Send packet out*/

		//cc = write(so, (char *) udprecord, (unsigned int) pktsize);

		(void) gettimeofday (&tp1, (struct timezone *) 0);

		elapsed_time = (double) tp1.tv_sec + (double) tp1.tv_usec / 1000000.0
				- (double) tp->tv_sec - (double) tp->tv_usec / 1000000.0;

		pktsend++; /* number of packets sent */


	}
	return 0;
}
