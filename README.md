# tmcc-bf
A derivative language of Brainfuck in C.<br>

The extension of the file must be `.tmcc`.
## Correspondence with Brainfuck
`SMD`: `+` <br>
`にゃんこ`: `-` <br>
`しの`: `>` <br>
`さばにき`: `<` <br>
`ゲェジ`: `.` <br>
`がりん`: `,` <br>
`NEMO`: `[` <br>
`キュゥ`: `]` <br>

## How to execution
1. compile tmccbf.c<br>
// I only used gcc, so I only know this.
```
gcc tmccbf.c -o tmccbf
```
2. run<br>
```
./tmccbf example.tmcc
```

## example code

input(hello.tmcc)

    SMDSMDSMDSMDSMDSMDSMDSMDSMDNEMOしのSMDSMDSMDSMDSMDSMDSMDSMDしのSMDSMDSMDSMDSMDSMDSMDSMDSMDSMDSMDしのSMDSMDSMDSMDSMDさばにきさばにき
    さばにきにゃんこキュゥしのゲェジしのSMDSMDゲェジSMDSMDSMDSMDSMDSMDSMDゲェジゲェジSMDSMDSMDゲェジしのにゃんこゲェジにゃんこにゃんこにゃんこにゃんこ
    にゃんこにゃんこにゃんこにゃんこにゃんこにゃんこにゃんこにゃんこゲェジさばにきSMDSMDSMDSMDSMDSMDSMDSMDゲェジにゃんこにゃんこにゃんこにゃんこにゃんこ
    にゃんこにゃんこにゃんこゲェジSMDSMDSMDゲェジにゃんこにゃんこにゃんこにゃんこにゃんこにゃんこゲェジにゃんこにゃんこにゃんこにゃんこにゃんこにゃんこ
    にゃんこにゃんこゲェジしのSMDゲェジしのSMDSMDSMDSMDSMDSMDSMDSMDSMDSMDゲェジ

output
```
Hello, world!
```

## LICENSE
[This software is released under the MIT License.](https://github.com/k-mrm/tmcc-bf/blob/master/LICENSE)

## Author
[k-mrm](https://github.com/k-mrm)
