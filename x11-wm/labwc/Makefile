# $FreeBSD$

PORTNAME=	labwc
DISTVERSION=	0.1.0
CATEGORIES=	x11-wm

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Openbox alternative for Wayland

LICENSE=	GPLv2

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
		wlroots>=0.11.0:x11-toolkits/wlroots
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig xorg
USE_GITHUB=	yes
USE_GNOME=	cairo libxml2 pango
USE_XORG=	pixman
GH_ACCOUNT=	johanmalm
PLIST_FILES=	"${MAYBE_SUID}bin/${PORTNAME}"

OPTIONS_DEFINE=	MANPAGES SUID X11
OPTIONS_DEFAULT=MANPAGES SUID X11

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz \
			man/man5/${PORTNAME}-actions.5.gz \
			man/man5/${PORTNAME}-config.5.gz \
			man/man5/${PORTNAME}-theme.5.gz

SUID_DESC=		setuid bit on "${PORTNAME}" binary (to claim DRM without seatd/console-kit-daemon)
SUID_VARS=		MAYBE_SUID="@(,,4755) "

X11_MESON_ENABLED=	xwayland

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build
# Respect PREFIX for system-wide config and Openbox themes
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		-e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/docs/${PORTNAME}-config.5.scd \
		${WRKSRC}/src/common/dir.c

.include <bsd.port.mk>
