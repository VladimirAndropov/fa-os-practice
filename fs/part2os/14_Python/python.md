System Programming in Python
---

The goal of this seminar is to practice in using Python modules that manage
facilities provided by the operation system. 

## Running programs in Python

Using the [os](https://docs.python.org/3/library/os.html) and
[sys](https://docs.python.org/3/library/sys.html) modules to run programs from Python scripts.

Read documentation on the `os.path.realpath(path)`, `os.system(command)`, `sys.executable`, and `sys.argv` methods.

Study the Python program below.

__dorun.py__:

```python
#!/usr/bin/env python3
'''
''' 
import sys
import os

Python = sys.executable
f = os.path.realpath(sys.argv[1])

os.system(f'{Python} {f} {" ".join(sys.argv[2:])}')
```

This program launches a program specified as command-line argument and passes it the
rest of the arguments. The program to be run can look as follows.

__torun.py__:

```python
#!/usr/bin/env python3
'''
'''
import sys
print(":", "-".join(sys.argv[1:]))
```

Run the program with `python3` and see the result:

    acos@acos-vm:~$ python3 dorun.py torun.py qwe ert ert
    : qwe-ert-ert

Run the program and pass it an invalid program to run. See the output:

    acos@acos-vm:~$ python3 dorun.py nothing_torun.py qwe ert ert

#### Task 01

Modify the __dorun.py__ program so that it checks whether the program to run exists
before trying to run it.

Use the [os.path.exists](https://docs.python.org/3/library/os.path.html#os.path.exists)
method to check whether the program exists.

If the file does not exist, print the "No _filename_" message to
[sys.stderr](https://docs.python.org/3/library/sys.html?sys.stderr).

Save the modified code to the __dochkrun.py__ file.

__dochkrun.py (solution)__:

```python
#!/usr/bin/env python3

import sys
import os

Python = sys.executable
f = os.path.realpath(sys.argv[1])

if os.path.exists(f):
    os.system(f'{Python} {f} {" ".join(sys.argv[2:])}')
else:
    print(f'No {f}!', file=sys.stderr)
```

## Creating processes in Python

When is required to spawn new processes, connect to their input/output/error pipes,
and obtain their return codes the [subprocess](https://docs.python.org/3/library/subprocess.html) module can be used.

#### Task 02

Study documentation on the [subprocess](https://docs.python.org/3/library/subprocess.html) module.

Rewrite the __dochkrun.py__ file to run the program using the
[subprocess.run](https://docs.python.org/3/library/subprocess.html#subprocess.run) function.

Save the resulting program to the __dosubrun.py__ file.

__dosubrun.py (solution)__:

```python
#!/usr/bin/env python3

import sys
import os
from subprocess import run

Python = sys.executable
f = os.path.realpath(sys.argv[1])

if os.path.exists(f):
    run([Python, f]+sys.argv[2:])
else:
    print(f"No {f}", file=sys.stderr)
```

## Using Pipes in Python

Pipes can be used to [replace shell pipelines](
https://docs.python.org/3.8/library/subprocess.html?highlight=subprocess#replacing-shell-pipeline).

The following shell command:
   
    output=$(dmesg | grep sda)

can be implemented in Python as follows:

```python
import subprocess as proc
p1 = proc.Popen(["dmesg"], stdout=proc.PIPE)
p2 = proc.Popen(["grep", "sda"], stdin=p1.stdout, stdout=proc.PIPE)
p1.stdout.close()  # Allow p1 to receive a SIGPIPE if p2 exits.
output = p2.communicate()[0]
```

Execute shell and Python and see the results.

#### Task 03

On the basis of the previous example,
write a Python program that pipelines two commands specified in the command line.
Both commands can have any number of arguments. Save the program to the pipecmd.py file.

_Hint_: You need to separate one program with arguments from another program with a special separator character.
For example, it can be “@”.
 
The command line can look like this:

```bash
acos@acos-vm:~$ python3 pipecmd.py date -u @ hexdump -C
00000000 d0 92 d1 81 20 d0 bc d0 b0 d1 8f 20 33 31 20 32 |.... ...... 31 2|
00000010 31 3a 31 33 3a 30 38 20 55 54 43 20 32 30 32 30 |1:13:08 UTC 2020|
00000020 0a                                              |.|
00000021
```

__pipecmd.py (solution)__:

```python
#!/usr/bin/env python3

import subprocess as proc import sys

d = sys.argv.index("@")
p1 = proc.Popen(sys.argv[1:d], stdout=proc.PIPE)
p2 = proc.Popen(sys.argv[d+1:], stdin=p1.stdout, stdout=proc.PIPE)
p1.stdout.close() # Allow p1 to receive a SIGPIPE if p2 exits.
output = p2.communicate()[0]
print(output.decode())
```

## Running Python Program in Different Processes

To execute different parts of a program in different processes,
the [multiprocessing](https://docs.python.org/3/library/multiprocessing.html) module can be used.
The example below runs a process using the [Process](
https://docs.python.org/3/library/multiprocessing.html#multiprocessing.Process) class.
   
__multiex.py__:

```python
from multiprocessing import Process
import os


def info(title):
   print(title)
   print('module name:', __name__)
   print('parent process:', os.getppid())
   print('process id:', os.getpid())


def f(name):
   info('function f')
   print('hello', name)


if __name__ == '__main__':
   info('main line')
   p = Process(target=f, args=('bob',))
   p.start()
   p.join()
```

#### Task 04

Modify the `multiex.py` program. Pass the `f` function running in another process
the additional argument `wait`, which specifies a delay in seconds.
It must be a random value from the range [1..5].

In the `f` function, print the `wait` argument together with `name`.
Then delay execution for the number of seconds specified in `wait`.

Use the [time.sleep](
https://docs.python.org/3/library/time.html#time.sleep) method to delay execution.

Use the [random.randrange](
https://docs.python.org/3/library/random.html#random.randrange) to generate a random value. 

Save the resulting program in the `multiex2.py` file.

__multiex2.py (solution)__:

```python
#!/usr/bin/env python3

from multiprocessing import Process
import time
import random


def f(name, wait):
   print(name, wait)
   time.sleep(wait)
   print('hello', name)


if __name__ == '__main__':
   p = Process(target=f, args=('bob',random.randrange(1,5)))
   p.start()
   p.join()
```

## Connecting Processes with Pipes

Exchange objects between processes using [pipes](
https://docs.python.org/3.8/library/multiprocessing.html#exchanging-objects-between-processes).

Here is an example:

```python
from multiprocessing import Process, Pipe


def f(conn):
   conn.send([42, None, 'hello'])
   conn.close()


if __name__ == '__main__':
   parent_conn, child_conn = Pipe()
   p = Process(target=f, args=(child_conn,))
   p.start()
   print(parent_conn.recv())   # prints "[42, None, 'hello']"
   p.join()
```

#### Task 05

Modify the `multiex2.py` program to send the `f"Hello, {name}!"` message
from the child to the parent process. Print it in the parent process.

Save the resulting program to the `multiexchat.py` file.

__multiexchat.py (solution)__:

```python
#!/usr/bin/env python3

from multiprocessing import Process, Pipe
import time


def f(conn):
   name, wait = conn.recv()
   print(name, wait)
   time.sleep(wait)
   conn.send(f"Hello, {name}!")
   conn.close()


if __name__ == '__main__':
   parent_conn, child_conn = Pipe()
   p = Process(target=f, args=(child_conn,))
   p.start()
   parent_conn.send(("bob", 4))
   res = parent_conn.recv()
   print(res)
   p.join()
```

#### Task 06

Modify the `multiex2.py` program to run multiple processes and wait for them to stop.
The name of a process is its index.
Number of processes must be specified as a command line argument (default value is 5).

Save the resulting program to the `multiexmany.py` file.

See the running processes with `ps`:
    
```python
acos@acos-vm:~$ python3 multiexmany.py &
[1] 2844
acos@acos-vm:~$ 0 4
4 3
1 2
3 2
2 2
ps -ef | grep python
acos     2844    2515  0 01:53 pts/0    00:00:00 python3 multiexmany.py
acos     2845    2844  0 01:53 pts/0    00:00:00 python3 multiexmany.py
acos     2846    2844  0 01:53 pts/0    00:00:00 python3 multiexmany.py
acos     2847    2844  0 01:53 pts/0    00:00:00 python3 multiexmany.py
acos     2848    2844  0 01:53 pts/0    00:00:00 python3 multiexmany.py
acos     2849    2844  0 01:53 pts/0    00:00:00 python3 multiexmany.py
acos     2851    2515  0 01:53 pts/0    00:00:00 grep --color=auto python
acos@acos-vm:~$ hello 1 2
hello 2 2
hello 3 2
hello 4 3
hello 0 4
[1]+  Finished        python3 multiexmany.py
```

__multiexmany.py (solution):__

```python
#!/usr/bin/env python3

from multiprocessing import Process
import time
import random
import sys


def f(name, wait):
   print(name, wait)
   time.sleep(wait)
   print('hello', name, wait)


if __name__ == '__main__':
   N = int(sys.argv[1]) if len(sys.argv)>1 else 5
   P = [Process(target=f, args=(i, random.randrange(1,5))) for i in range(N)]
   res = [p.start() for p in P]
   res = [p.join() for p in P]
```

## Process Pooling in Python

Tasks can be parallelized using [pools](
https://docs.python.org/3.8/library/multiprocessing.html#multiprocessing.pool.Pool).
They allow distributing tasks among the specified number of worker processes.
Here is an example:

```python
from multiprocessing import Pool

def f(x):
    return x*x

if __name__ == '__main__':
    with Pool(5) as p:
        print(p.map(f, [1, 2, 3]))
```

#### Task 07

Modify the `multiex2.py` program to run multiple tasks using a pool.
Number of tasks must be specified as a command-line argument (default value is 5).
The size of pool is fixed and equals 6.
The `f` function must return the wait value multiplied by 10.
Print the aggregated result returned by the `Pool.map` method.
Save the resulting program to the `multiexpool.py` file.

__multiexpool.py (solution)__:
```python

#!/usr/bin/env python3

from multiprocessing import Pool
import time
import random
import sys


def f(args):
   name, wait = args
   print(name, wait)
   time.sleep(wait)
   return wait*10


if __name__ == '__main__':
   N = int(sys.argv[1]) if len(sys.argv)>1 else 5
   pool = Pool(6)
   pars = [(i, random.randrange(1,5)) for i in range(N)]
   res = pool.map(f, pars)
   print(res)
   pool.close()
```
