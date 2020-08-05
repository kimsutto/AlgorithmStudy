bool twoStrings(string a, string b){
    int checkA[26]={0,};
    int checkB[26]={0,};
    for(int i=0; i<a.size(); i++){
        checkA[a[i]-'a'] ++;
    }
    for(int i=0; i<b.size(); i++){
        checkB[b[i]-'a'] ++;
    }
    for(int i=0; i< 26; i++){
        if(checkA[i]!=0 && checkB[i]!=0) 
            return true;
    }
    return false;
}

private static final Scanner scanner = new Scanner(System.in);

public static void main(String[] args) throws IOException {
   int q = scanner.nextInt();

   scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

   for (int qItr = 0; qItr < q; qItr++) {
       String s1 = scanner.nextLine();
       String s2 = scanner.nextLine();

       bool result = twoStrings(s1, s2);
       System.out.println(result);
   }
   scanner.close();
  }
}
