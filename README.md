# wcc

The unix `wc` command have an option on Linux to report the shortest line in a text file (`wc -l` ).
This utility just calculate the minimum and the maximum line length of an ascii file, as well
as the number of lines.

```command
$ wcc /etc/passwd
31 98 42
$ wc -lL /etc/passwd
  42   98 /etc/passwd
```
