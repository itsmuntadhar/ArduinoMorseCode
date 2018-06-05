/*
    Author: Muntadhar Haydar (@sparkist97)
    Desc: A simple program to visualize a morse code through an LED.
    June 5th, 2018.

*/

int dotPause = 750;
int linePause = 1500;
int betweenPause = 250;
int boundaryPause = 450;
//
char table[38][6] =
    {
        "000.-", //a
        "0-...", //b
        "0-.-.", //c
        "00-..", //d
        "0000.", //e
        "0..-.", //f
        "00--,", //g
        "0....", //h
        "000..", //i
        "0.---", //j
        "00-.-", //k
        "0.-..", //l
        "000--", //m
        "000-.", //n
        "00---", //o
        "0.--.", //p
        "0--.-", //q
        "00.-.", //r
        "00...", //s
        "0000-", //t
        "00..-", //u
        "0...-", //v
        "00,--", //w
        "0-..-", //x
        "0-.--", //y
        "0--..", //z
        "-----", //0
        ".----", //1
        "..---", //2
        "...--", //3
        "....-", //4
        ".....", //5
        "-....", //6
        "--...", //7
        "---..", //8
        "----."  //9
};

void toMorse(char *str)
{
    for (byte i = 0; i < strlen(str); i++)
    {
        byte index = str[i] >= 48 && str[i] <= 57 ? str[i] - 22 : str[i] >= 65 && str[i] <= 90 ? str[i] - 65 : str[i] >= 97 && str[i] <= 122 ? str[i] - 97 : 255;
        if (index != 255)
        {
            for (byte j = 0; j < 5; j++)
            {
                if (table[index][j] == '.')
                {
                    PORTB |= 0x20; // turn on the led.
                    delay(dotPause);
                    PORTB &= 0xDF; // turn off the led.
                }
                else if (table[index][j] == '-')
                {
                    PORTB |= 0x20;
                    delay(linePause);
                    PORTB &= 0xDF;
                }
                delay(betweenPause);
            }
        }
    }
    delay(boundaryPause);
}

void setup()
{
    DDRB |= 0x20;
    toMorse("SOS");
}

void loop()
{
    
}