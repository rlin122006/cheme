{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { self, nixpkgs }:
    let pkgs = nixpkgs.legacyPackages.x86_64-linux;
    in {
       devShells.x86_64-linux.default = pkgs.mkShell {
        packages = with pkgs; [
          clang-tools
        ];

        shellHook = ''
          export CEDEV="$PWD/.toolchain/CEdev"
          export PATH="$CEDEV/bin:$CEDEV/binutils/bin:$PATH"
        '';
      };
    };
}
