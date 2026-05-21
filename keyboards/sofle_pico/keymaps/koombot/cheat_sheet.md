# QMK CLI Cheatsheet (Vial)

## Setup
```bash
qmk config user.qmk_home=~/path/to/vial-qmk   # point QMK at vial-qmk instead of qmk_firmware
qmk config user.keyboard=sofle_pico            # set default keyboard
qmk config user.keymap=koombot                 # set default keymap
qmk config                                     # view current config
```

## Building
```bash
make sofle_pico:koombot                        # compile
make sofle_pico:koombot:flash                  # compile and flash
make sofle_pico:koombot 2>&1 | grep error      # show only errors
```

## Flashing
```bash
make sofle_pico:koombot:flash                  # flash via CLI
# or use QMK Toolbox with the .uf2 file from the .build/ folder
```

## Useful
```bash
qmk doctor                                     # check environment is healthy
qmk compile --compiledb -kb sofle_pico -km koombot  # generate compile_commands.json for VS Code
qmk config user.overlay_dir="$(realpath .)"   # set userspace path (run from userspace folder)
```

## Git (saving to GitHub)
```bash
git add .
git commit -m "your message"
git push

git pull --rebase                              # sync with remote before pushing
git remote -v                                  # check where you're pushing to
git config core.autocrlf false                 # suppress LF/CRLF warnings on Windows
```

## File locations
```
vial-qmk/
└── keyboards/
    └── sofle_pico/
        └── keymaps/
            └── koombot/
                ├── keymap.c
                ├── rules.mk
                ├── config.h
                └── vial.json      ← required for Vial
```

## Notes
- Run all `make` commands from the root of `vial-qmk/`
- Use QMK MSYS2 terminal on Windows, not PowerShell
- Compiled firmware is in `.build/` as a `.uf2` file

## Image Generation
-  If you ever regenerate  from source images, set "Byte orientation" to Vertical in image2cpp.

## shift backspace sends delete instead
-  Go to vial.rocks
- pen Vial → Key Overrides tab
- Click an empty slot
- Set Trigger key: Backspace
- Set Trigger mods: Shift (left, right, or both)
- Set Replacement: Delete
- Make sure the entry is enabled
