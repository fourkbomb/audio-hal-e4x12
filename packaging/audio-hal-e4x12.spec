Name:       audio-hal-e4x12
Summary:    TIZEN Audio HAL for Exynos4x12
Version:    0.1.5
Release:    0
VCS:        magnolia/adaptation/ap_samsung/audio-hal-e4x12#a568942051241d60e37c6738466a2a5058f260c0
Group:      System/Libraries
License:    Apache-2.0
URL:        http://tizen.org
Source0:    audio-hal-e4x12-%{version}.tar.gz
BuildRequires: pkgconfig(alsa)
BuildRequires: pkgconfig(vconf)
BuildRequires: pkgconfig(iniparser)
BuildRequires: pkgconfig(dlog)

%description
TIZEN Audio HAL for Exynos4x12

%prep
%setup -q -n %{name}-%{version}

%build
%if 0%{?tizen_build_binary_release_type_eng}
export CFLAGS="$CFLAGS -DTIZEN_ENGINEER_MODE"
export CXXFLAGS="$CXXFLAGS –DTIZEN_ENGINEER_MODE"
export FFLAGS="$FFLAGS -DTIZEN_ENGINEER_MODE"
%endif

%autogen
%configure

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}

mkdir -p %{buildroot}/usr/share/license
cp LICENSE.APLv2 %{buildroot}/usr/share/license/%{name}

%make_install

%post 
/sbin/ldconfig

%postun 
/sbin/ldconfig

%files
%manifest audio-hal-e4x12.manifest
%defattr(-,root,root,-)
/usr/lib/libtizen-audio.so
%{_datadir}/license/%{name}
