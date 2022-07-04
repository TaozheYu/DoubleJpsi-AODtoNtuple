void CalculateCS(float Frac1, float Frac1_err, float Data_num){
    /*
    Double_t data_num = 22550; 
    Double_t frac1 = 0.796;
    Double_t frac1_err = 0.009;

    Double_t frac2 = 0.798;
    Double_t frac2_err = 0.013;
    */
    
   Double_t data_num = Data_num;//401615; 
   Double_t frac1 = Frac1;//0.750;
   Double_t frac1_err = Frac1_err;//0.002;

   Double_t frac2 = 1-Frac1;//0.765;
   Double_t frac2_err = Frac1_err;//0.005;
      
   Double_t frac1_sq = frac1*frac1;
   Double_t frac1_sq_err = sqrt(frac1*frac1*frac1_err*frac1_err + frac1*frac1*frac1_err*frac1_err);
   
   Double_t frac2_sq = frac2*frac2;
   Double_t frac2_sq_err = sqrt(frac2*frac2*frac2_err*frac2_err + frac2*frac2*frac2_err*frac2_err);
   
   Double_t frac12 = 2*frac1*frac2;
   Double_t frac12_err = sqrt(frac2*frac2*frac1_err*frac1_err + frac1*frac1*frac2_err*frac2_err);
       
   cout<<"Double Jpsi fraction is "<<frac1_sq<<" +- "<<frac1_sq_err<<endl;
   cout<<"Double Jpsi events is "<<frac1_sq*data_num<<" +- "<<frac1_sq_err*data_num<<endl;
   cout<<endl;
   cout<<"Jpsi + comb. fraction is "<<frac12<<" +- "<<frac12_err<<endl;
   cout<<"Jpsi + comb. events is "<<frac12*data_num<<" +- "<<frac12_err*data_num<<endl;
   cout<<endl;
   cout<<"comb. + comb. fraction is "<<frac2_sq<<" +- "<<frac2_sq_err<<endl;
   cout<<"comb. + comb. events is "<<frac2_sq*data_num<<" +- "<<frac2_sq_err*data_num<<endl;
   cout<<endl;

   float N_corr = frac1_sq*data_num;
   float N_corr_err = frac1_sq_err*data_num;
 
   float Lumi = 36.3;

   float Br = 0.0593;
   float Br_err = 0.0006;

   float cross_section = N_corr/(Lumi*Br*Br);
   float Br_2_err = sqrt(2*Br*Br*Br_err*Br_err);

   float cross_section_err = sqrt((N_corr*N_corr*Br_2_err*Br_2_err + N_corr_err*N_corr_err*Br*Br*Br*Br)/(Br*Br*Br*Br*Br*Br*Br*Br))/Lumi;

   cout<<"The Jpsi pair production is "<<cross_section/1000000<<" +- "<<cross_section_err/1000000<<" nb"<<endl;; 


}
