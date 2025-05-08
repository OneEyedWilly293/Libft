# C Library from Scratch
Finishing the Libft project has been a true milestone in my programming journey. At first, it felt overwhelming to recreate so many standard C functions from scratch, but as I progressed, I started to really understand how these core tools work under the hood. I learned how important careful memory management is-making sure to allocate, use, and free memory correctly to avoid leaks or crashes.

The project also taught me the value of writing clean, well-structured code that follows strict standards (the Norm). This discipline forced me to break down problems into small, manageable pieces and to be precise with naming and formatting. Debugging became much easier as my code got more organized.

Implementing string and memory manipulation functions gave me a much deeper appreciation for how C handles data, and building my own linked list library was my first real experience with dynamic data structures. I also got comfortable with using Makefiles and managing a multi-file project in Git.

Overall, Libft gave me a strong foundation in C and boosted my confidence to tackle more complex projects. I now have a personal library of functions that I can reuse and improve as I continue my studies.

If you’re curious about any specific part of the project or want to know more about my learning process, feel free to ask!

## <ins>How to run the test</ins>
```json
"terminal.integrated.scrollback": 100000
```
> Add the this to your `json`(in VSCode) file to accommodate the scroll-back length when running the compiled test.

OR

```bash
"cc -Wall -Wextra -Werror -g -lbsd *.c &> (your output name).tt"
```
> compile the files with the "function_test" file and output into Text Template file(.tt) to save the output into a file.


### <ins>Other Libft Testers</ins>
I highly recommend testing your libft projects with multiple tests to ensure it's functionality.

1) Tripouille's Tests[https://github.com/Tripouille/libftTester/tree/master].
> *Through this test, I've learned about handling "SIZE_MAX" for ft_calloc.*

2) Jtoty's Tests[https://github.com/jtoty/Libftest].
> *This has tests for some additional functions, that were not in our project list.*

3) alelievr's test[https://github.com/alelievr/libft-unit-test].
> *I haven't used this test myself but saw other peers using it.*