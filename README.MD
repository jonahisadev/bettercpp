# Better CPP

This is a personal-use project that I will be developing in my free time. It aims
to speed up C++ development with better and more readable implementations of data
structures, as well as some other utility functions I'm tired of writing in every
project.

### Philosophy

I'm really tired of certain STL structures. Often times, I grow weary of STL code
because it can be:

* Unreadable (iterators)
* Lacking in functionality (`std::string`)
* Too complicated (citation needed)

The goal of this project is to provide implementations of structures that I find
fall under those qualifications. It's also a fun exercise to implement different
constructs and ideas, to see how they really work under the hood (such as smart
pointers, or vectors).

This project also strives to be lightweight, and easy to integrate. I want everything
to remain in a header as much as possible, as that tends to be the easiest way to
integrate. As mentioned before, this project should play nicely with STL. I don't
want this project to be an all-or-nothing game. Pick and choose what you need, and
use STL for the things you think it does well.