Libft

### <ins>How to run the test</ins>
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
> *This has tests for some additional functions, that were not in our project list.

3) alelievr's test[https://github.com/alelievr/libft-unit-test].
> *I haven't used this test myself but saw other peers using it.