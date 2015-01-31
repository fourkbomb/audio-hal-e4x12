Name:       audio-hal-e4x12
Summary:    TIZEN Audio HAL for Exynos4x12
Version:    0.1.9
Release:    0
VCS:        magnolia/adaptation/ap_samsung/audio-hal-e4x12#a568942051241d60e37c6738466a2a5058f260c0
Group:      System/Libraries
License:    Apache-2.0
URL:        http://tizen.org
Source0:    audio-hal-e4x12-%{version}.tar.gz
BuildRequires: pkgconfig(vconf)
BuildRequires: pkgconfig(iniparser)
BuildRequires: pkgconfig(dlog)
BuildRequires: pkgconfig(alsa)
Provides: libtizen-audio.so

%description
TIZEN Audio HAL for Exynos4x12

%prep
%setup -q -n %{name}-%{version}

%build
export CFLAGS="$CFLAGS -DTIZEN_DEBUG_ENABLE"
export CXXFLAGS="$CXXFLAGS ?“DTIZEN_DEBUG_ENABLE"
export FFLAGS="$FFLAGS -DTIZEN_DEBUG_ENABLE"

%autogen
%configure

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
mkdir -p %{buildroot}/etc/smack/accesses.d
cp -arf audio_hal_sys_file_access.efl %{buildroot}/etc/smack/accesses.d
mkdir -p %{buildroot}/usr/share/license
cp LICENSE.Apache-2.0 %{buildroot}/usr/share/license/%{name}
%make_install

%post 
/sbin/ldconfig

%postun 
/sbin/ldconfig

%files
%manifest audio-hal-e4x12.manifest
%defattr(-,root,root,-)
/etc/smack/accesses.d/audio_hal_sys_file_access.efl
/usr/lib/libtizen-audio.so
/usr/share/license/%{name}
