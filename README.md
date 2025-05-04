# IDA List Sorter
An in-memory patch for the IDA disassembler that automatically sorts certain lists. For people with lots of column header clicking experience.

Auto-sorts the following:
* Ctrl-L popups for jumping to names, structures and enums
* T popup for defining a structure offset operand (both simple and extended version; the extended version is originally not sortable at all, but now is.)
* M popup for selecting an enum.
* Alt-Q popup for selecting a structure.
* Alt-Y popup for selecting a union member.
* Structure selection popup for the decompiler's "Convert to struct*" command.

To use, simply extract glu32.dll into your IDA folder (the one containing ida64.exe). It would've been nicer to make this into a plugin, of course, but I didn't want to set up and learn the SDK just for this tiny project.

Tested on IDA 7.6, 8.2, and 9.0, but should work on others too. The DLL only uses Qt functions and is thus independent from IDA internals.
