# Standard textclass definition file. Taken from initial LyX source code
# Author : Matthias Ettrich <ettrich@informatik.uni-tuebingen.de>
# Transposed by Pascal AndrИ <andre@via.ecp.fr>
# Heavily modifed and enhanced by several developers.

# Cut & paste from various LyX layouts plus some major modifications
# GOST textclass (c) 2001 Vitaly Lipatov, Boris Balabanov
# Our parts licensed under GPL
# This include file contains all numbered sectionning-related
# commands that are useful for article-like document classes, but not
# for letters.


# Section style definition
Style Section
  Margin		Dynamic
  LatexType		Command
  LatexName		section
  NeedProtect		1
  NextNoIndent		0
  LabelSep		xxx
  ParSkip		0.4
  TopSep		1.3
  BottomSep		0.7
  ParSep		0.7
  Align			Block
  AlignPossible		Block, Left
  LabelType		Counter_Section
  LabelStringAppendix   "Приложение "

  # standard font definition
  Font 
    Series 		Bold
    Size		Larger
  EndFont

End

# Subsection style definition
Style Subsection
  Margin		Dynamic
  LatexType		Command
  LatexName		subsection
  NeedProtect		1
  NextNoIndent		0
  LabelSep		xxx
  ParSkip		0.4
  TopSep		0.9
  BottomSep		0.5
  ParSep		0.5
  Align			Block
  AlignPossible		Block, Left
  LabelType		Counter_Subsection

  # standard font definition
  Font 
    Series 		Bold
    Size		Large
  EndFont

End

# Subsubsection style definition
Style Subsubsection
  Margin		Dynamic
  LatexType		Command
  LatexName		subsubsection
  NeedProtect		1
  NextNoIndent		0
  LabelSep		xxx
  ParSkip		0.4
  TopSep		0.7
  BottomSep		0.4
  ParSep		0.4
  Align			Block
  AlignPossible		Block, Left
  LabelType		Counter_SubSubSection

  # standard font definition
  Font 
    Series 		Bold
    Size		Normal
  EndFont

End

# Paragraph style definition
Style Paragraph
  Margin		Dynamic
  LatexType		Command
  LatexName		paragraph
  NeedProtect		1
  NextNoIndent		0
  LabelSep		xxx
  ParSkip		0.4
  TopSep		0.4
  BottomSep		0
  ParSep		0.4
  Align			Block
  AlignPossible		Block, Left
  LabelType		Counter_Paragraph

  # standard font definition
  Font 
    Series 		Bold
    Size		Normal
  EndFont

End

# Subparagraph style definition
Style Subparagraph
  Margin		Dynamic
  LatexType		Command
  LatexName		subparagraph
  NeedProtect		1
  NextNoIndent		0
  LeftMargin		MM
  LabelSep		xxx
  ParSkip		0.4
  TopSep		0.4
  BottomSep		0
  ParSep		0.4
  Align			Block
  AlignPossible		Block, Left
  LabelType		Counter_SubParagraph

  # standard font definition
  Font 
    Series 		Bold
    Size		Normal
  EndFont

End
