%define ENC1 koi8-r
%define ENC2 cp1251

Name: lyx-gost
Version: 1.3.1
Release: alt1

Summary: The GOST class files for LyX in koi8-r encoding
Summary(ru_RU.KOI8-R): ����� ������ GOST ��� LyX � ��������� koi8-r
License: GPL
Group: Office
URL: http://rulyx.narod.ru

Packager: Vitaly Lipatov <lav@altlinux.ru>

Source: %name-%version.tar.bz2

BuildArchitectures: noarch
BuildPreReq: iconv
PreReq: lyx >= 1.3.0

%description
The %name package contains the LyX/LaTeX class for preparing documents
according to Russian GOST's demands.

%description -l ru_RU.KOI8-R
����� %name �������� ����� ��� LyX/LaTeX, ��������������� ���
���������� ����������� ��������� ������������ � ������������
� ���� 2.105-95 (� ������� � ��������� ���������).

%package koi8-r
Summary: The GOST class files for LyX in koi8-r encoding
Summary(ru_RU.KOI8-R): ����� ������ GOST ��� LyX � ��������� koi8-r
Group: Office

Provides: lyx-gost
Conflicts: lyx-gost-cp1251
Obsoletes: lyx-gost


%description koi8-r
The %name package contains the LyX/LaTeX class for preparing documents
according to Russian GOST's demands.

%description koi8-r -l ru_RU.KOI8-R
����� %name �������� ����� ��� LyX/LaTeX, ��������������� ���
���������� ����������� ��������� ������������ � ������������
� ���� 2.105-95 (� ������� � ��������� ���������).

%package cp1251
Summary: The GOST class files for LyX in cp1251 encoding
Summary(ru_RU.KOI8-R): ����� ������ GOST ��� LyX � ��������� cp1251
Group: Office

Provides: lyx-gost
Conflicts: lyx-gost-koi8-r
Obsoletes: lyx-gost

%description cp1251
The %name package contains the LyX/LaTeX class for preparing documents
according to Russian GOST's demands.

%description cp1251 -l ru_RU.KOI8-R
����� %name �������� ����� ��� LyX/LaTeX, ��������������� ���
���������� ����������� ��������� ������������ � ������������
� ���� 2.105-95 (� ������� � ��������� ���������).


%prep
%setup -q

%install

mkdir -p $RPM_BUILD_ROOT%_datadir/lyx/{layouts,templates,clipart}

# ������������ �������� ����� � ��� ������� ���������
# ������ ���������� �� ����� ���� ��� ������ :)

for TARENC in %ENC1 %ENC2; do

#	for f in layouts/*.layout; do
#		iconv -f %ENC1 -t $TARENC "$f" | sed -e "s/.inc/-$TARENC.inc/g" >"$RPM_BUILD_ROOT/%_datadir/lyx/layouts/`basename $f .layout`-$TARENC.layout"
#	done

	for f in layouts/*.inc; do
		iconv -f %ENC1 -t $TARENC "$f" >"$RPM_BUILD_ROOT/%_datadir/lyx/layouts/`basename $f .inc`-$TARENC.inc"
	done
	
	for f in templates/*.lyx; do
		iconv -f %ENC1 -t $TARENC "$f" | sed -e "s/koi8-r/$TARENC/g" >"$RPM_BUILD_ROOT/%_datadir/lyx/templates/`basename $f .lyx`-$TARENC.lyx"
	done

	mkdir -p $RPM_BUILD_ROOT%_datadir/doc/%name-$TARENC-%version
	cd doc
	for f in *;	do
		iconv -f %ENC1 -t $TARENC "$f" >"$RPM_BUILD_ROOT/%_datadir/doc/%name-$TARENC-%version/$f"
	done
	cd -
done

for i in layouts/*.layout clipart/*; do
	install -D -m644 $i ${RPM_BUILD_ROOT}/%_datadir/lyx/$i
done

%post %ENC1
echo "Configuring LyX for your system..."
cd %prefix/share/lyx
./configure --srcdir

%post %ENC2
echo "Configuring LyX for your system..."
cd %prefix/share/lyx
./configure --srcdir

%preun

%postun %ENC1
echo "Configuring LyX for your system..."
cd %prefix/share/lyx
./configure --srcdir

%postun %ENC2
echo "Configuring LyX for your system..."
cd %prefix/share/lyx
./configure --srcdir

%files %ENC1
%doc doc/*
%_datadir/lyx/layouts/*-%ENC1.inc
%_datadir/lyx/layouts/gost.layout
%_datadir/lyx/clipart/*
%_datadir/lyx/templates/*-%ENC1.lyx


%files %ENC2
%doc doc/*
%_datadir/lyx/layouts/*-%ENC2.inc
%_datadir/lyx/layouts/gost.layout
%_datadir/lyx/clipart/*
%_datadir/lyx/templates/*-%ENC2.lyx


%changelog
* Mon Mar 31 2003 Vitaly Lipatov <lav@altlinux.ru> 1.3.1-alt1
- updated for LyX 1.3.1
- new version of lyx-gost (see ChangeLog)

* Wed Dec 04 2002 Vitaly Lipatov <lav@altlinux.ru> 1.2-alt5
- corrected for tetex-2.0
- cleanup spec
- tested with LyX 1.2.1

* Mon Nov 11 2002 Stanislav Ievlev <inger@altlinux.ru> 1.2-alt4
- rebuild

* Sat Jul 06 2002 Vitaly Lipatov <lav@altlinux.ru> 1.2-alt3
- normalize code of textclass and gost frames
- packages for both encoding (koi8-r & cp1251)

* Fri Jun 14 2002 Vitaly Lipatov <lav@altlinux.ru> 1.2-alt2
- back to single source package for two destination
- update for LyX 1.2.0
- doc2lyx convertor removed
- add noarch option

* Sun Apr 14 2002 Vitaly Lipatov <lav@altlinux.ru> 1.2-alt1
- new version
- split in two package

* Tue Dec 22 2001 23:01:01 Vitaly Lipatov <lav@altlinux.ru> 1.1-alt1
- russian description charset fixed
- add new template delop.lyx
- new version of class GOST
- russian documentation for LyX moved to lyx-rusdoc

* Tue Dec 11 2001 11:19:09 Vitaly Lipatov <vitlav@mail.ru> 1.0-alt1
- first version
