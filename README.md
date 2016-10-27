# PigLatin
This program takes a sentence/phrase as input and converts it to Pig Latin (see wikipedia)

https://en.wikipedia.org/wiki/Pig_Latin

##Rules
 - Words that start with a vowel (A, E, I, O, U) simply have "WAY" appended to the end of the word.
 - Words that start with a consonant have all consonant letters up to the first vowel moved to the end of the word (as opposed to just the first consonant letter), and "AY" is appended.
     ('Y' is counted as a vowel in this context)

##Special cases
 - This program interprets vowel and consonant sounds accordingly
 - Special 'y' cases are handled differently based on prefix context

##This program needs:
 - delimiters
 - contraction translation
 
 I modeled my program after the style here:
 http://www.snowcrest.net/donnelly/piglatin.html
