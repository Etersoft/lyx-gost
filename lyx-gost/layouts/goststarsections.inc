# Standard textclass definition file. Taken from initial LyX source code
# Author : Matthias Ettrich <ettrich@informatik.uni-tuebingen.de>
# Transposed by Pascal André <andre@via.ecp.fr>
# Heavily modifed and enhanced by several developers.

# Cut & paste from various LyX layouts plus some major modifications
# GOST textclass (c) 2001 Vitaly Lipatov, Boris Balabanov
# Vitaly Lipatov (c) 2007
# Our parts licensed under GPL

# This include files contains all non numbered versions of the
# sectioning-related commands that are useful for article-like
# document classes, but not for letters. It should be Input after
# modying the style of the regular sectioning layouts.

Format 4
# Section* style definition
Style Section*
  CopyStyle		Section
  Margin		Static
  LatexName		section*
  LabelType		No_Label
End

# Subsection* style definition
Style Subsection*
  CopyStyle		Subsection
  Margin		Static
  LatexName		subsection*
  LabelType		No_Label
End

# Subsubsection* style definition
Style Subsubsection*
  CopyStyle		Subsubsection
  Margin		Static
  LatexName		subsubsection*
  LabelType		No_Label
End

# Paragraph* style definition
Style Paragraph*
  CopyStyle		Paragraph
  Margin		Static
  LatexName		paragraph*
  LabelType		No_Label
End

# Subparagraph* style definition
Style Subparagraph*
  CopyStyle		Subparagraph
  Margin		Static
  LatexName		subparagraph*
  LabelType		No_Label
End

