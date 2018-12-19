# GOST textclass definition file.
# Based on Article textclass definition file for LyX, latex.ltx, article.cls
# and other files from /usr/share/texmf (tetex version)
# (c) 2001-2002 Boris Balabanov
# (c) 2001-2003 Vitaly Lipatov
# Vitaly Lipatov (c) 2007
# Our parts licensed under GPL
# $Id$


Preamble

	\usepackage{indentfirst} % Начинать абзацы с красной строки
	\usepackage{multicol} % Многоколоночность
	\usepackage{textcomp} % Ввод различных знаков
	\usepackage{floatflt}
	\usepackage{footnpag} % Внешний вид сносок
	\usepackage{ifthen}
	\usepackage{mathtext} % Позволяет использовать русские буквы в формулах
	\usepackage{babel} % Нужен здесь, а LyX 1.2.0 определяет его только после
	\usepackage{geometry}%для остановки плавающих объектов                                                           
	\usepackage{float}
	\usepackage{rotating}%вращение информации
	\geometry{verbose,a4paper}%установка полей
	\usepackage{graphicx}
	\usepackage{calc} %Для возможности численных расчетов
	\usepackage[bottom]{footmisc}  %Для установки сносок всегда внизу страницы
	% Чтобы строчки никогда не вылезали за поля
	\sloppy

	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% Настройки размера области текста
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	\setlength{\headheight}{0pt}
	\setlength{\headsep}{0pt}
	\setlength{\topmargin}{-1.0cm}
	\setlength{\textwidth}{16.3cm}
	\setlength{\textheight}{22.5cm}
	\setlength{\oddsidemargin}{0.5cm}
	\setlength{\evensidemargin}{0pt}
	\setlength{\marginparsep}{0pt}
	\setlength{\marginparpush}{0pt}
	\parindent=15mm  % Абзацный отступ
	%\pargostzero=0mm
	\setlength{\leftmargini}{\parindent}
	\addtolength{\leftmargini}{5mm}


	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% Переопределение пунктов
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	%\addtocounter{secnumdepth}{-2}

	\ifnum \c@secnumdepth < 4
		\newcommand{\theengost}{\thesection.\@arabic\c@engost}%              
		\newcounter{engost}[section]
	\else                                                                         
    	\ifnum \c@secnumdepth < 5
			\newcommand{\theengost}{\thesubsection.\@arabic\c@engost}%
			\newcounter{engost}[subsection]
		\else                                                                       
			\ifnum \c@secnumdepth < 6
				\newcommand{\theengost}{\thesubsubsection.\@arabic\c@engost}%
				\newcounter{engost}[subsubsection]
			\else
				\ifnum \c@secnumdepth < 7
					\newcommand{\theengost}{\theparagraph.\@arabic\c@engost}%
					\newcounter{engost}[paragraph]
				\else
					\ifnum \c@secnumdepth < 8
						\newcommand{\theengost}{\thesubparagraph.\@arabic\c@engost}%
						\newcounter{engost}[subparagraph]
					\else
						\newcommand{\theengost}{\@arabic\c@engost}%
						\newcounter{engost}
					\fi
				\fi
        	\fi                                                                       
    	\fi                                                                         
    \fi 
	% Окружение Пункт (engost) для реализации нумерации по ГОСТ
	\newenvironment{engost}%
	{%
		\renewcommand\item{%
			\par%
			\refstepcounter{engost}%
			\theengost
			%\arabic{section}.\arabic{subsection}.\arabic{engost}%
			\quad%
		}%
    }%

	\newcounter{ensubgost}[engost]	    			
	\renewcommand{\theensubgost}{\theengost.\arabic{ensubgost}}%              
	\newenvironment{ensubgost}
    {%
    	\renewcommand{\item}{%
		    \par%
		    \refstepcounter{ensubgost}%
		    \theensubgost%
		    \quad%
	    }%
    }%

	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% Раздел с новой страницы
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	\newcommand{\gostnewpage}{\newpage}
	
	% Размер наименования в основной надписи
	\newcommand{\setgostnamesize}{\small}

	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% Переопределение вида разделов
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	\renewcommand\section{%
		\renewcommand{\theengost}{\thesection.\@arabic\c@engost}
		\setcounter{engost}{0}
		\gostnewpage
		\@startsection {section}{1}{\parindent}%
			{-6.5ex \@plus -1ex \@minus -.2ex}%
			{2.3ex \@plus.2ex}%
			{\normalfont\Large\bfseries}}
	\renewcommand\subsection{%
		\renewcommand{\theengost}{\thesubsection.\@arabic\c@engost}
		\setcounter{engost}{0}
		\@startsection{subsection}{2}{\parindent}%
			{-3.25ex\@plus -1ex \@minus -.2ex}%
			{1.5ex \@plus .2ex}%
			{\normalfont\large\bfseries}}
	\renewcommand\subsubsection{%
		\renewcommand{\theengost}{\thesubsubsection.\@arabic\c@engost}
		\setcounter{engost}{0}
		\@startsection{subsubsection}{3}{\parindent}%
			{-3.25ex\@plus -1ex \@minus -.2ex}%
			{1.5ex \@plus .2ex}%
			{\normalfont\normalsize\bfseries}}
	\renewcommand\paragraph{%
		\renewcommand{\theengost}{\theparagraph.\@arabic\c@engost}
		\setcounter{engost}{0}
		\@startsection{paragraph}{4}{\parindent}%
			{3.25ex \@plus1ex \@minus.2ex}%
			{-1em}%
			{\normalfont\normalsize\bfseries}}
	\renewcommand\subparagraph{%
		\renewcommand{\theengost}{\thesubparagraph.\@arabic\c@engost}
		\setcounter{engost}{0}
		\@startsection{subparagraph}{5}{\parindent}%
			{3.25ex \@plus1ex \@minus .2ex}%
			{-1em}%
			{\normalfont\normalsize\bfseries}}

	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% Титульный лист
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	\def\gostgrifsoglasovano#1{\gdef\@gostgrifsoglasovano{#1}} 
	\def\gostgrifutverjdeno#1{\gdef\@gostgrifutverjdeno{#1}} 
	\def\gosttitleobject#1{\gdef\@gosttitleobject{#1}}
	\def\gosttitledocument#1{\gdef\@gosttitledocument{#1}} 
	\def\gostoboznacheniein#1 #2 {\gdef\@gostoboznacheniespec{#1}\gdef\@gostoboznacheniedok{#2}\gdef\@gostoboznachenie{#1#2}}
	\def\gostoboznachenie#1{\gostoboznacheniein #1 }
	\def\gosttitlecompany#1{\gdef\@gosttitlecompany{#1}} 
	\def\gostutverdil#1{\gdef\@gostutverdil{#1}}
	\def\gostnormokontroler#1{\gdef\@gostnormokontroler{#1}} 
	\def\gostrazrabotchik#1{\gdef\@gostrazrabotchik{#1}} 
	\def\gostproveril#1{\gdef\@gostproveril{#1}} 
	\def\gostispolnitel#1{\gdef\@gostispolnitel{#1}} 
  
 	\gosttitlecompany{}
	\gostnormokontroler{}
	\gostrazrabotchik{}
	\gostproveril{}
	\gostoboznachenie{}
	\gosttitledocument{}
	\gosttitleobject{~ }
	\gostgrifutverjdeno{}
	\gostgrifsoglasovano{}
	\gostutverdil{}
	\gostispolnitel{}

  
	%  собственно команды формирования титульного листа
	\renewcommand\maketitle{%
		\begin{titlepage}%
			\let\footnotesize\small
			\let\footnoterule\relax
			\let \footnote \thanks
			%  \null\vfil
			\begin{center}
				{\LARGE \@gosttitlecompany \par}%
				\vskip 1cm
			\end{center}
			\par%
			%{%\raggedleft%
			\begin{tabular}{l}%
				\ignorespaces                            
				\@gostgrifsoglasovano
			\end{tabular}                                                                
			\hfill
			\begin{tabular}{l}%
				\ignorespaces                            
				\@gostgrifutverjdeno
			\end{tabular}
			\vspace{1.4em}                                                               
			\par
			%}
			\vskip 60\p@
			\begin{center}%
				\vskip 3em%
				{\large%
				\lineskip 2cm%
				\addtolength{\parskip}{\baselineskip}
				%      \begin{tabular}[t]{c}%
				%        \@author
				%		\par
				\LARGE{\@gosttitleobject}
				\par
				\@gosttitledocument
				\par
				\@gostoboznachenie
				%      \end{tabular}
				\par
				}%
				\vfill
				\begin{flushleft}
					%\addtolength{\parskip}{\baselineskip}
					%исполнители:
					%\par
					%\vskip 5pt
					%\hskip 1cm
					\parindent=1cm
					%\setlength{\baselineskip}{2\baselinestretch}
					\baselineskip=0.8cm
					\par
					%\begin{tabular}{l}%
					
						\@gostispolnitel
					%\end{tabular}
				\end{flushleft}
				\vfill
				\vfill
				{\large \@date \par}%
			\end{center}
	%		\par
	%  \
	%  \@thanks
	%  \vfil\null
	\end{titlepage}%
	\addtocounter{page}{1}
	\setcounter{footnote}{0}%
	\global\let\thanks\relax
	\global\let\maketitle\relax
	\global\let\@thanks\@empty
	\global\let\@author\@empty
	\global\let\@date\@empty
	%  \global\let\@gosttitlecompany\@empty
	\global\let\@gostgrifsoglasovano\@empty
	\global\let\@gostgrifutverjdeno\@empty
	%  \global\let\@gostoboznachenie\@empty
	%  \global\let\@gosttitleobject\@empty
	%  \global\let\@gosttitledocument\@empty
	\global\let\gostgrifsoglasovano\relax
	\global\let\gostgrifutverjdeno\relax
	\global\let\gostoboznachenie\relax
	\global\let\gosttitleobject\relax
	\global\let\gosttitledocument\relax
	\global\let\gosttitlecompany\relax
	\global\let\gostispolnitel\relax
	\global\let\author\relax
	\global\let\date\relax
	\global\let\and\relax
	}

	%%% Настройки для фоновых рамок
	\usepackage{eso-pic,graphicx}
	\newcommand\BackgroundPicture[2]{%
		\setlength{\unitlength}{1pt}%
		\put(0,\strip@pt\paperheight){%
		\parbox[t][\paperheight]{\paperwidth}{%
		\vfill 
		\centering\includegraphics[angle=#2]{#1}
		\vfill 
	}}} %

	\usepackage{lastpage}
	\usepackage{everyshi}
	% \renewcommand\thepage{\arabic{page} of \pageref{LastPage}}
	\usepackage{epsfig}
	\usepackage{psfrag}
	%\usepackage{calc}

	\newcounter{gostszv}
	\newcounter{gostlastpage}
	\newcounter{gostszvv}
	\newlength{\gostorigline}%
	\newlength{\gostadnomin}%
	\newsavebox{\newgostboxik}%

	% Для вывода текста в бокс с указанными координатами углов
	% 1,2 координаты x,y левого нижнего угла, 3,4 правого верхнего угла
	% 5 выравнивание 6 текст
	\def\spbox#1#2#3#4#5#6{%
		\put(#1,#2){%
			\setcounter{gostszv}{#3-#1}%
			\setcounter{gostszvv}{#4-#2}%
			\makebox(\value{gostszv},\value{gostszvv})[#5]{#6}%
		}%
	}

	% Сжимает текст, если он не влезает в указанный box
	\def\spformedbox#1#2#3#4#5#6{%
		\setcounter{gostszv}{#3-#1}%
		\setcounter{gostszvv}{#4-#2}%
		\setlength{\gostadnomin}{#3pt - #1pt}%ширина поля
		{%
			\sbox{\newgostboxik}{#6}%
			\settowidth{\gostorigline}{\usebox{\newgostboxik}}%
			\put(#1,#2){%
				\ifthenelse{\lengthtest{\gostorigline<\gostadnomin}}%
					{\makebox(\value{gostszv},\value{gostszvv})[#5]%
						{\usebox{\newgostboxik}}}%
					{\makebox(\value{gostszv},\value{gostszvv})[#5]%
						{\resizebox{\gostadnomin}{\height}{\usebox{\newgostboxik}}}}%
			}%
		}%
	}

	\def\spvertnormbox#1#2#3#4#5#6#7{%
		\setcounter{gostszv}{#3-#1}%
		\setcounter{gostszvv}{#4-#2}%
		\setlength{\gostadnomin}{#4pt - #2pt}%высота заданного бокса
		{%
			\sbox{\newgostboxik}{#6}%
			\settoheight{\gostorigline}{\usebox{\newgostboxik}}%
			\put(#1,#2){%
				\ifdim \gostorigline > \gostadnomin
					{\makebox(\value{gostszv},\value{gostszvv})[#5]%
						{\usebox{\newgostboxik}}}%
				\else
					{\makebox(\value{gostszv},\value{gostszvv})[#5]%
						{#7}}%
				\fi
			}%
		}%
	}

	% Вывод текста в вертикальный бокс
	\def\vspbox#1#2#3#4#5#6{%
		\put(#1,#2){%
			\setcounter{gostszv}{#3-#1}%
			\setcounter{gostszvv}{#4-#2}%
			\begin{sideways}%
				\makebox(\value{gostszv},\value{gostszvv})[#5]{#6}%
			\end{sideways}%
		}%
	}%

	%\def\two@digits#1{\ifnum#1<10 0\fi\number#1}

	% Путь к файлам рамок
	\def\pathtosharedresource{/usr/share/lyx/clipart/}
	% Можно указать gost_frame_compat для немного укороченных рамок,
	% для тех принтеров, которые не могут печатать близко к нижнему
	% краю
	\def\namegostframe{gost_frame}
	\newcommand\GostFrameCompatible{%
		\def\namegostframe{gost_frame_compat}%
	}
	% !!!!!!!
	% Временно сразу включаем совместимые рамки
	\GostFrameCompatible
	\def\thegostpage{\thepage}
	\def\thegostlastpage{\pageref{LastPage}}
	\newcommand\NoPageNumbers{%
		\def\thegostpage{}%
		\def\thegostlastpage{}%
	}%
	%\NoPageNumbers


%\def\lastpage@putgostcounter{
%   \immediate\write\@auxout{\string
%   \setcounter{gostlastpage}{\value{page} + 2}%
%   }%
%   }

% В конце документа добавляем пустую страницу
\AtEndDocument{%
\clearpage%
%\AddToShipoutPicture{\BackgroundPicture{/tmp/changelist.eps}{0}%
}%


	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% Нижний колонтитул. Заполняем рамки текстом. 
	% Координаты задаются в pt, соответствующие координатам в просмотре
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	\let\@oldoddfoot\@oddfoot
	\def\@oddfoot{%
		\unitlength=1pt
		%  \begin{picture}(0,0)(87,0)
		%  \begin{picture}(0,0)(100,2)
		%  \begin{picture}(0,0)(100,68)
		% увеличение 3 числа - сдвиг влево
		% увеличение 4 числа - сдвиг вниз
		\ifthenelse{\equal{\namegostframe}{gost_frame}}%
			{\begin{picture}(0,0)(86,68)}%
			{\begin{picture}(0,0)(86,68)}%
		%
		% Почему-то не oddfoot не вызывается для первой страницы
		\spbox{483}{15}{562}{22}{r}{{\tiny Формат A4}}
		\ifnum \thepage = 1
			\else
		\ifnum \thepage = 2
			% Вторая страница
			%\spbox{483}{15}{562}{22}{r}{{\tiny Формат A4}}
			\spbox{524}{67}{579}{79}{c}{\thegostlastpage}
			\spbox{481}{67}{522}{79}{c}{\thegostpage}
			\spformedbox{106}{81}{167}{93}{l}{\textsl{\small\@gostrazrabotchik}}
			\spformedbox{105}{67}{167}{80}{l}{\textsl{\small\@gostproveril}}
			\spformedbox{105}{39}{167}{51}{l}{\textsl{\small\@gostnormokontroler}}
			\spformedbox{105}{25}{167}{37}{l}{\textsl{\small\@gostutverdil}}
			\spbox{242}{96}{578}{136}{c}{\LARGE{\@gostoboznachenie}}
			\vspbox{38}{660}{202}{673}{c}{\normalsize\@gostoboznacheniespec}
			\spbox{245}{25}{430}{92}{c}
				{\parbox{60mm}{\centering\setgostnamesize{\@gosttitleobject} \\ \@gosttitledocument}}
		\else
			% Последующие страницы
			%\spbox{483}{15}{562}{22}{r}{{\tiny Формат A4}}
			\spbox{552}{25}{578}{45}{c}{\thegostpage}
			\spbox{242}{25}{549}{65}{c}{\LARGE{\@gostoboznachenie}}
			%\setcounter{gostszv}{\pageref{LastPage}}%
			%\setcounter{gostszv}{1}%
			%\def\thelastpage\\string\pageref{LastPage}
			%\ifnum  \thelastpage = 1
			%	ZZZZZZZZZZZZZ
			%\fi
			%\ifthenelse{\value{page} = \value{gostlastpage}}%
			%	{123-------------------------}%
			%	{ZZZZZZZZZZZZZ \thepage = \arabic{gostlastpage} = \pageref{LastPage} = \expandafter\@secondoftwo{LastPage} = \csname r@LastPage\endcsname ZZZZZZZZZZZZZ}%
		\fi
		\fi
		\end{picture}
	}
	%\def\@oddfoot{}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% После вывода  каждой страницы выполняем следующий код
%% Для вывода рамок
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\EveryShipout{%
  \ClearShipoutPicture%
  \ifnum \thepage = 1
%параметры второго листа
    \AddToShipoutPicture{\BackgroundPicture{\pathtosharedresource \namegostframe 1.pdf}{0}}%
    \enlargethispage{2.3cm}%
  \else%
  \ifnum \thepage = 2
    \AddToShipoutPicture{\BackgroundPicture{\pathtosharedresource \namegostframe 2.pdf}{0}}%
    \enlargethispage{-2.7cm}
  \else%
%параметры остальных листов
    \AddToShipoutPicture{\BackgroundPicture{\pathtosharedresource \namegostframe 3.pdf}{0}}%
%    \AddToShipoutPicture{\BackgroundPicture{/tmp/changelist.eps}{0}}%
  \fi%
  \fi%
}
\let\@evenfoot\@oddfoot
\let\@evenhead\@oddhead
%\AddToShipoutPicture{\BackgroundPicture{\pathtosharedresource \namegostframe 1.pdf}{0}}
\setlength{\textheight}{24.7cm}
%\enlargethispage{2.3cm}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Настройка вида подписей к рисункам и таблицам
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\usepackage[center]{caption2}
\renewcommand{\captionlabeldelim}{~ ---}
%\renewcommand\captionmargin{0.2cm}
% Подпись к рисунку
\addto\captionsrussian{%
  \def\figurename{{\cyrРисунок}}%
}
% Команды для вывода подписей различного вида
\newcommand{\captiontable}[1]{\caption{#1}}
\newcommand{\captionfigure}[1]{\caption{#1}}
%\defcaptionstyle{#1}{#2}%

%\newcommand{\@ldtable}{}
%\let\@ldtable\table
%\renewcommand{\table}{%
%	\setlength{\@tempdima}{\abovecaptionskip}%
%	\setlength{\abovecaptionskip}{\belowcaptionskip}%
%	\setlength{\belowcaptionskip}{\@tempdima}%
%	\@ldtable}%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Настройка номера формулы и ссылки на нее
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  \def\@eqnnum{{\normalfont \normalcolor \theequation}}
  \renewcommand{\theequation}{(\arabic{equation})}%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Центрирование содержания
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\renewcommand\tableofcontents{%
\begin{center}
  {
  \Large\bf\contentsname
  }
\end{center}
    \@starttoc{toc}%
    \newpage
}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Вид строчек в содержании
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  \renewcommand{\l@subsection}{\@dottedtocline{2}{0em}{2.3em}}
  \renewcommand{\l@subsubsection}{\@dottedtocline{3}{0em}{3em}}

\renewcommand*\l@section[2]{%
  \ifnum \c@tocdepth >\z@
    \addpenalty\@secpenalty
    \addvspace{1.0em \@plus\p@}%
%    \setlength\@tempdima{1.5em}%
    % Ширина поля для номера страницы
    %\renewcommand\@pnumwidth{5.55em}
    \begingroup
%      \leftskip 0 em\relax \rightskip \@tocrmarg \parfillskip -\rightskip
%      \parindent 0em\relax\@afterindenttrue
%      \interlinepenalty\@M
%      \leavevmode
    % Ширина номера пункта в содержании
      \@tempdima 1.7 em\relax

      \parindent \z@ \rightskip \@pnumwidth
      \parfillskip -\@pnumwidth
%      \parfillskip -\rightskip
      \leavevmode %\bfseries
%      \advance\leftskip\@tempdima \hskip -\leftskip
      \advance\leftskip \@tempdima \null\nobreak\hskip -\leftskip
%    Дальше выводим номер и название строки содержания
     {\bfseries {#1}\nobreak }%
     \leaders\hbox{%
	 	$\m@th
        \mkern \@dotsep mu\hbox{.}\mkern \@dotsep%
        mu$}\hfill%
     \nobreak%
%    Здесь выводится номер страницы
%     \hb@xt@\@pnumwidth{\hss #2}\par
     \hb@xt@\@pnumwidth{\hfil\normalfont \normalcolor #2}%
     \par%
%
%      
%      #1\nobreak\hfil \nobreak\hb@xt@\@pnumwidth{\hss #2}\par
    \endgroup
  \fi}

%  \renewcommand*{\l@section}{\@dottedtocline{1}{0em}{2.3em}}
  


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Тире в перечислении (ненумерованном списке)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\renewcommand{\labelitemi}{\normalfont\bfseries{--}}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Команды, формирующие представление названия раздела
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Отвечает за представление номера раздела в тексте
\newcommand{\sectname}[2]{%
		\csname the#1\endcsname\quad
}

% Отвечает за представление номера раздела в содержании
\newcommand{\sectnameintoc}[2]{%
		\protect\numberline{\csname the#1\endcsname}%
}

% Команды между номером раздела и его названием
\newcommand{\sectdop}[1]{%
	\raggedright%
	\interlinepenalty \@M%
}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%% Взято из latex.ltx и исправлено под наши требования %%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\def\@sect#1#2#3#4#5#6[#7]#8{%
  \ifnum #2>\c@secnumdepth
    \let\@svsec\@empty
  \else
  % Если выводим нумерацию разделов
    \refstepcounter{#1}%
	% Здесь был @seccntformat
    \protected@edef\@svsec{\sectname{#1}{#2}\relax}%
  \fi
  \@tempskipa #5\relax
  \ifdim \@tempskipa>\z@
    \begingroup
      #6{%
	  	
	    % Выводится номер раздела
        \@hangfrom{\hskip #3\relax\@svsec}%
	% Выводится название раздела
	\sectdop{#2}#8
	\@@par}%
    \endgroup
    \csname #1mark\endcsname{#7}%
    \ifnum #2>\c@tocdepth \else
      \addcontentsline{toc}{#1}{%
        \ifnum #2>\c@secnumdepth \else
%       \ifnum #2>\c@tocdepth \else
          \sectnameintoc{#1}{#2}%
        \fi
        #7}%
    \fi
  \else
    \def\@svsechd{%
	\hyphenation{#8}%
      #6{\hskip #3\relax
      \@svsec #8}%
      \csname #1mark\endcsname{#7}%
      \addcontentsline{toc}{#1}{%
        \ifnum #2>\c@secnumdepth \else
          \protect\numberline{\csname the#1\endcsname}%
        \fi
        #7}}%
  \fi
  \@xsect{#5}}
\def\@xsect#1{%
  \@tempskipa #1\relax
  \ifdim \@tempskipa>\z@
    \par \nobreak
    \vskip \@tempskipa
    \@afterheading
  \else
    \@nobreakfalse
    \global\@noskipsectrue
    \everypar{%
      \if@noskipsec
        \global\@noskipsecfalse
       {\setbox\z@\lastbox}%
        \clubpenalty\@M
        \begingroup \@svsechd \endgroup
        \unskip
        \@tempskipa #1\relax
        \hskip -\@tempskipa
      \else
        \clubpenalty \@clubpenalty
        \everypar{}%
      \fi}%
  \fi
  \ignorespaces}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%% Взято из bk12.clo и исправлено под наши требования %%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Настройки для 1-го уровня списка
\def\@listi{\leftmargin\leftmargini
%            \parsep 5\p@  \@plus2.5\p@ \@minus\p@
            \parsep 0\p@  \@plus2.5\p@ \@minus\p@
            \topsep 3\p@ \@plus3\p@   \@minus2\p@
%				\topsep \z@
%            \itemsep1\p@  \@plus2.5\p@ \@minus\p@}
            \itemsep 1\p@}
\let\@listI\@listi
\@listi
% Настройки для 2-го уровня списка
\def\@listii {\leftmargin\leftmarginii
              \labelwidth\leftmarginii
              \advance\labelwidth-\labelsep
              \topsep    1\p@   \@plus2.5\p@ \@minus\p@
%				\topsep \z@
              \parsep    1\p@ \@plus\p@    \@minus\p@
              \itemsep   \parsep}
% Настройки для 3-го уровня списка (в ГОСТ не используется)
\def\@listiii{\leftmargin\leftmarginiii
              \labelwidth\leftmarginiii
              \advance\labelwidth-\labelsep
%              \topsep    2.5\p@\@plus\p@\@minus\p@
				\topsep \z@
              \parsep    \z@
              \partopsep \p@ \@plus\z@ \@minus\p@
              \itemsep   \topsep}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Определение изменений в оформлении приложений
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\renewcommand\appendix{\par

%\addtocounter{tocdepth}{-1}
\setcounter{tocdepth}{1}

  \renewcommand{\section}{
    \renewcommand{\theengost}{\thesection.\@arabic\c@engost}
    \setcounter{engost}{0}
    \@startsection{section}
     {1}
     {0mm}
     {-\baselineskip}
     {\baselineskip}
     {\newpage\Large\bf}}%


   \addtocontents{toc}{\vskip 12pt }

  \setcounter{section}{0}%
  \setcounter{subsection}{0}%

% Отвечает за представление названия раздела в тексте
\renewcommand{\sectname}[2]{%
	\ifnum ##2 > 1
		\csname the##1\endcsname\quad
	\else
		%\appendixname\ \csname the##1\endcsname
		\protect\makebox[\textwidth]{\appendixname\ \csname the##1\endcsname}%

	\fi
}

% Отвечает за представление названия раздела в содержании
\renewcommand{\sectnameintoc}[2]{%
	\ifnum ##2 > 1
		\protect\numberline{\csname the##1\endcsname}%
	\else
		\protect\appendixname\ \numberline{\csname the##1\endcsname}
	\fi
}

% Отвечает за перенесение названия раздела на другую строку в приложении
\renewcommand{\sectdop}[1]{%
	\ifnum ##1 > 1
		\raggedright%
	\else
		\centering%
		{\\\raisebox{3pt}{\em\normalsize(обязательное)}}\\
	\fi
}

  \renewcommand{\thesection}{\GostAsbuk{section}}%

% Нумерация рисунков с указанием номера приложения
  \@addtoreset{figure}{section}%                                                   
  \renewcommand{\thefigure}{\thesection.\arabic{figure}}%
  
% Нумерация таблиц с указанием номера приложения
  \@addtoreset{table}{section}%                                                   
  \renewcommand{\thetable}{\thesection.\arabic{table}}%
  
% Нумерация формул с указанием номера приложения
  \@addtoreset{equation}{section}%                                                   
  \renewcommand{\theequation}{(\thesection.\arabic{equation})}%
}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Сноски со скобкой
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 \renewcommand\thefootnote{\@arabic\c@footnote)}%   

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Исключение двусмысленных русских букв из алфавита 
%для нумерации приложений
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\def\GostAsbuk#1{\expandafter\@GostAsbuk\csname c@#1\endcsname}                         
\def\@GostAsbuk#1{\ifcase#1\or                                                      
\CYRA\or\CYRB\or\CYRV\or\CYRG\or\CYRD\or\CYRE\or\CYRZH\or                     
\CYRI\or\CYRK\or\CYRL\or\CYRM\or\CYRN\or                      
\CYRP\or\CYRR\or\CYRS\or\CYRT\or\CYRU\or\CYRF\or\CYRH\or
\CYRC\or\CYRSH\or\CYRSHCH\or\CYREREV\or\CYRYU\or                     
\CYRYA\else\@ctrerr\fi}                                                       


% Для выравнивания длинных таблиц
\usepackage{longtable}
\LTleft=\z@
\LTright=\fill

\def\LT@makecaption#1#2#3{%                                                     
  \LT@mcol\LT@cols l{\hbox to\z@{\parbox[t]\LTcapwidth{%                    
      \sbox\@tempboxa{#1{#2\captionlabeldelim{} }#3}%                                                
          {\box\@tempboxa\hfil}%                                 
          \endgraf}%                                               
    \hss}}} 

\newcommand{\rem}[1]{}



\def\NoFrames{
\ClearShipoutPicture
\renewcommand\BackgroundPicture[2]{}
\let\@oddfoot\@oldoddfoot
}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%% Далее текст документа %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

EndPreamble

