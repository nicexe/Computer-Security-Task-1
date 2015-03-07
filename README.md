# Computer-Security-Task-1
This is the first task that I have to deliver on a Computer Security course I am attending

## Developing a simple symmetric cipher
The simplest classical symmetric cipher is the Caesar cipher. The purpose of this task is to implement functions for encryption/decryption with the Caesar cipher and test their functionality.

1. Implement encryption/decryption functions that take a key (as an integer in 0, 1, 2, ..., 25), and a string. The function should only operate on the characters 'a', 'b', ..., 'z' (both upper and lower case), and it should leave any other characters, unchanged.
2. Implement a function that performs a brute force attack on a cipher text. It should print a list of the keys and associated decryptions. It should also take an optional parameter that takes a substring and only prints out potential plain-texts that contain that decryption.
3. Show the output of your encrypt function on the following (key, plain-text) pairs:
  * (12, "Get me a vanilla ice cream, make it a double.")
  * (15, "I don't much care for Leonard Cohen.")
  * (16, "I like root beer floats.")
4. Show the output of your decrypt function on the following (key, cipher-text) pairs:
  * (12, "nduzs ftq buzq oazqe.")
  * (3, "fdhvdu qhhgv wr orvh zhljkw.")
  * (20, "ufgihxm uly numnys.")

You are free to use a programming language of your choice.

## Deliverables:
1. A document in **pdf** format illustrating the output for all subtasks above.
2. The source code of the program
