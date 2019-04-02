{ pkgs ? (import <nixpkgs> {})}:
with pkgs;

stdenv.mkDerivation {
  name = "xftmatch";
  src = ./.;
  buildInputs = [ freetype xorg.libX11 xorg.libXft ];
  installFlags = [ "DESTDIR=$(out)" ];
}
