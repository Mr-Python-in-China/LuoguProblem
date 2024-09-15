import cyaron as c
from string import ascii_lowercase

while True:
    io=c.IO('/tmp/in','/tmp/out')
    io.input_writeln(1)
    s=''.join(c.choice(ascii_lowercase) for _ in range(c.randint(1,10)))
    io.input_writeln(s)
    c.Compare.program('./CF1984D.bitfile',std_program= './CF1984D_std.bitfile',input=io)
