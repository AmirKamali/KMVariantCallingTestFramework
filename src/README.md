KMVariantCallingTestFramework
===============
This command line tool helps testing different Variant calling programs

./KMVariantCallingTestFramework -vcf "/Users/Amir/Desktop/GATK/EXP/GATK\ Testing\ Scripts/2-SNPCall/raw_variants.vcf" -r 95 -v 45



SAMPLE VCF FILE:
#CHROM	POS	ID	REF	ALT	QUAL	FILTER	INFO	FORMAT	sample1
chrM	105	.	C	G	1430.77	.	AC=1;AF=0.500;AN=2;BaseQRankSum=0.019;ClippingRankSum=0.630;DP=95;FS=0.000;MLEAC=1;MLEAF=0.500;MQ=37.00;MQ0=0;MQRankSum=0.809;QD=15.06;ReadPosRankSum=-1.256;SOR=0.595	GT:AD:DP:GQ:PL	0/1:50,45:95:99:1459,0,1652



Sample Results:
./KMVariantCallingTestFramework
Preparing to check :95 - 45
0/1:50,45:95:99:1459,0,1652Inside is:45:95:99:1459
Check ratio is:45:95
PASSED