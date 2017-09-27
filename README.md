# Encrypt_Decrypt_File

Coding challenge:

Ready-to-execute program that can accomplish the following tasks:
  1. Randomized Cypher program, that can encrypt any text file and will output the encrypted text-file along with a cypher reference number.
  2. Reversing previous program's operation, taking the encrypted text-file along with cypher reference number to output the original text-file.

I developer 2 programs: encrypt.cpp and decrypt.cpp
  encrypt.cpp will take original-text-file and output_file as command-line arguments. this porgram will ecrypt the contents of original-text-file and put them in output_file. This program will encrypt the data of original file by generating a cypher reference number. It is similar to synchronous key. 
  decrypt.cpp will take the output of encrypt.cpp and returns the original-file contents. The input of decrypt.cpp are 3 command-line arguments
  1. output file of encrypt.cpp that is the encrypted_text_file
  2. output file to put the decrypted contents
  3. cypher reference number from encrypt.cpp's output.

commands to execute:
  keep the encrypt.cpp and decrypt.cpp in same directory. Now create 3 textfiles. ( original.txt ), ( encrypted.txt ) and ( decrypted.txt ).  
  put your data you want to encrypt in ( original.txt )
  keep encrypted.txt and decrypted.txt as empty

    step 1:    g++ -std=c++11 encrypt.cpp -o encrypt
    
    step 2:   ./encrypt original.txt encrypted.txt

 output:  Encrypted successfully. Cypher reference number is 27

    step 3:    g++ -std=c++11 decrypt.cpp -o decrypt

    step 4:    ./decrypt encrypted.txt decrypted.txt

  output:  Decrypted successfully.

Testing:  compare both original.txt and decrypted.txt 
To compare 2 files:  
	cmp --silent original.txt decrypted.txt || echo "Files are different"
	
The above command will compare two files. If there is a difference, it will print "Files are different" , if the files are same, it doesnt do anything.

I also checked with many different types of textfiles and all of them passed this test.

This application also works with recursively encrypting and decrypting. 

encrypt(encrypt(encrypt(original text))) = decrypt(deecrypt(decrypt(encrypted text )))

I have some other ideas to implement this encryption. I spent significant amount of time researching about standard encryption algorithms, what type of keys they take and encrypt text, etc. In the beginning, I  couldnt find any algorithm that can take a single number as key and return the text which will use the same value to decypt. 

Then I tried to implement my own simple encryption-decrytion application following the requirements you specified in the email. This application is far more vulnerable if the length of text is big. because as it is similar to substitution cypher, it is easily predictable to see repeated encrypted symbols and assigning them to 'e' (based on the historical data, 'e' is the most used character in sentences).  I also took care of not to get 32 as cypher reference number because, if my text has many capital alphabet, then they will just be converting into small alphabet after encrytion. 

One another idea I have is to generate cypher reference number and then increase its length to the size of the text to be encrypted. 
example:  if my original text is "Hello World!" and my generated cypher reference number is 4

I will manipulate 4 such that its length should be equal to the length of my text. i.e. 12 
like writing multiples of 4 and appending it to a string.
multiples of 4 = 4 ,8 ,12 ,16 ,20, 24, 28 ...
now appending them to a string be like:  "481216202428" and now adding each number to corresponding character in the original text.

original text   :    H  e  l  l  0     W  o  r  l  d  !    
	   key :     4  8  1  2  1  6  2  0  2  4  2  8

adding ASCII(original text) + key , we get encrypted text                 

encrypted text: L  m  m  n  p  &  Y  o  t  p  f  )

so now my encryted text is  " *Lmmnp&Yotpf)* "

This is comparitively more secure to the previous implementation. Because they cannot break easily using frequent analysis. as each character is converted with different padding.

                                                                                                                       ---***---

