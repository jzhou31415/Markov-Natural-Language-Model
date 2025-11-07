# Markov-Natural-Language-Model
### Description
A natural language model that uses Markov's Algorithm. Uses probability to predict the most likely next character following a ``k-length`` string from an input ``.txt`` file.

## Usage
Download all the ``.cpp`` and ``.h`` files as well as the ``Makefile`` from this repo. Make sure whatever environment you are running in has ``g++`` compiler installed. Then run the following commands:
    
    make
    ./wordgen "path to input text file" k-value n-characters
- ``"path to input text file"`` - path to the input text file the algorithm uses, some sample text is provided in the repo
- ``k-value`` - level of analysis you want to use for Markov's algorithm (minimum of ``1``, cannot be greater than the amount of characters in the input text file or the ``n`` value)
- ``n-characters`` - amount of characters you want the algorithm to output.

If your n value is large enough you can extract the output to a text file using `` > text.txt``

### Example Run:
    make
    ./wordgen text-files/twain.txt 25 2000
### Output:
    Level 25: 
    CHAPTER I
    "TOM!"
    No answer.
    "TOM!"
    No answer.
    "What's gone with that boy,  I wonder? You TOM!"
    No answer.
    The old lady pulled her spectacles down and looked over them about the room; then she put them up and looked out under them. She seldom or never looked THROUGH them for so small a thing as a boy; they were her state pair, the pride of her heart, and were built for "style," not service--she could have seen through a pair of stove-lids just as well. She looked perplexed for a moment, and then said, not fiercely, but still loud enough for the furniture to hear:
    "Well, I lay if I get hold of you I'll--"
    She did not finish, for by this time she was bending down and punching under the bed with the broom, and so she needed breath to punctuate the punches with. She resurrected nothing but the cat.
    "I never did see the beat of that boy!"
    She went to the open door and stood in it and looked out among the tomato vines and "jimpson" weeds that constituted the garden. No Tom. So she lifted up her voice at an angle calculated for distance and shouted:
    "Y-o-u-u TOM!"
    There was a slight noise behind her and she turned just in time to seize a small boy by the slack of his roundabout and arrest his flight.
    "There! I might 'a' thought of that closet. What you been doing in there?"
    "Nothing."
    "Nothing! Look at your hands. And look at your mouth. What IS that truck?"
    "I don't know, aunt."
    "Well, I know. It's jam--that's what it is. Forty times I've said if you didn't let that jam alone I'd skin you. Hand me that switch."
    The switch hovered in the air--the peril was desperate--
    "My! Look behind you, aunt!"
    The old lady whirled round, and snatched her skirts out of danger. The lad fled on the instant, scrambled up the high board-fence, and disappeared over it.
    His aunt Polly stood surprised a moment, and then broke into a gentle laugh.
    "Hang the boy, can't I never learn anything? Ain't he played me tricks enough like that for me to be looking out for him by this time? But old fools is