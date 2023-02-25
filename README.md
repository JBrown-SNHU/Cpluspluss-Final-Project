# Cpluspluss-Final-Project
CS-210-J7279 Programming Languages

Summary of Project:

1st Part: 
  The main first declares vector<Produce> produceList and Produce currProduce from the Produce class in Produce.h
  It then makes a call from fileLoader passing these variables as arguements (referenced so it will return to main).
  fileLoader reads from an input .txt file and assigns produce in the file to produce list.
  If there are repeats in the file, then the amount of the item is updated.
  fileLoader then outputs the info as a .dat file.

  2nd Part: 
  The main then displays the menu with 4 options.
  Option 1:look up an item to output the amout of the item sold.
  Option 2: print a list of items sold that day.
  Option 3: print a list of items sold that day in histogram form.
  Option 4: exits the program.
 
Question: What did you do particularly well?
  
  The seperating of fileLoader from the main program. The fileLoader program has nothing to do with the user, and it took up a great deal of space in my       main(). When I orginally submitted the project I was not able to find a way to have fileLoader serve as its own unique program seperate from the main, and bring that data from the list back into the main. After I submitted it, I went back and tried difference things until I found that you could pass the vector as a referece to return it back to the main.

Question: Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
    
  I found out how to seperate fileLoader, so I was pretty proud of that. Another area that I could imporve is to pass produceList as a pointer. Doing so        and adding destructors with it to the Produce class would make data managament more efficient. I also could pass more of the menu option as function to help make the code a little cleaner.
  
Question: Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  
  I struggled the most with figuring out how to use the reference to pass variables in functions. When I first did the project I completely forgot about references and tried to add a vector as a return type; however, a vector is not a valid return type (as far as I know) and it did not work out. I ended up getting furstrated with it and decided to just include it in the main for now, since I was pressed for time. And would go back and change it later if I figured it out.

Question: What skills from this project will be particularly transferable to other projects or course work?
  
  Linking other files, referencing variables, and and utilizing functions more effectively will definitely tranlate into other project and courses in the future, and I look forward to building on these and other fundamental skills.

Question: How did you make this program maintainable, readable, and adaptable?
  
  By making functions where ever I could (though there were places I could have added more), and adding in-line comments to explain my coding process.
  
