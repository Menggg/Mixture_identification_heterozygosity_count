# Mixture_identification_heterozygosity_count

This is a effective simulation sofeware for mixture simulation under assumption that the DNA concentrition of all the contributor is balanced. 
The pre-compiled execurate file for Linux and source code are availabe. User could use demo files including genotype data file and index file to do test running.


Quick start command line: <br />
./myMix --data demo_genotype.traw --sim_index demo_index_noc_2.sim --out test --snp 18 --sample 2504 --sim_round 50 --noc_number 2  --type 2


Input data: <br />
Genotype data file and index file are requied.
Genotype data file format is .traw format of PLINK (https://www.cog-genomics.org/plink/2.0/formats#traw) including m SNPs and n samples. <br />
Index file is a text file each row include NOC (number of contributors) number that randomly sampled from 1 to n (sample size). <br />
Additionally, some parameters need to be specifyed as follow, <br />
--snp is the number of SNPs in genotype file <br />
--sample is the number of samples in genptype file, also need to be consistant with index file <br />
--sim_round is the number of simulated mixture samples, must be less or equivalent to the number of rows in index file <br />
--noc_number is the number of contributor in mixture, must be less or equivalent to the number of columns in index file <br />
--type is the type of simulation, 1 refers to non-contributor exclusion simulation, 2 referes to number of contributor identification simulation <br />
--out give the prefix of output file name. <br />
