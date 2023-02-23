# IDA List Sorter
An in-memory patch for the IDA disassembler that automatically sorts certain lists. For people with lots of column header clicking experience.

Auto-sorts the following:
* Functions tab
* Imports tab
* Exports tab
* Local Types tab
* Names tab
* Ctrl-L popups for jumping to names, structures and enums
* T popup for defining a structure offset operand (both simple and extended version; the extended version is originally not sortable at all, but now is.)

To use, simply extract glu32.dll into your IDA folder (the one containing ida64.exe). It would've been nicer to make this into a plugin, of course, but I didn't want to set up and learn the SDK just for this tiny project.

Tested on IDA 7.6 and 8.2, but should work on others too. The DLL only hooks Qt functions and is thus independent from IDA internals.
