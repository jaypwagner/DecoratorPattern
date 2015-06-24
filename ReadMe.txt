========================================================================
    CONSOLE APPLICATION : DecoratorPattern Project Overview
========================================================================
This is an example of the Decorator Pattern....
The objects don't make too much sense but the pattern is solid.

Lessons Learned:
The Decorator Pattern is used to attach additional responsiblities to an object dynamically, it is an alternative to subclassing to extend functionality to an object without adding to its Inheritance Hierachy.

The core object is recursively wrapped with behavior and state during runtime.

Possible Uses:
This pattern can be used to wrap streams with additional functionality such as compression, or formatting. 
ie: 
instead of EncryptingZippingStream 
new EncryptingStream(new ZippingStream(new SimpleStream(str)));
