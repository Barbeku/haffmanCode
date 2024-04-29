#include <stdio.h>
#include <string.h>
#include "frequency.h"
#include "haffmanTree.h"
#include "decodeEncode.h"

char *text = "William Shakespeare's name is synonymous with many of the famous lines he wrote in his plays and prose. Yet his poems are not nearly as recognizable to many as the characters and famous monologues from his many plays.  In Shakespeare's era (1564-1616), it was not profitable but very fashionable to write poetry. It also provided credibility to his talent as a writer and helped to enhance his social standing. It seems writing poetry was something he greatly enjoyed and did mainly for himself at times when he was not consumed with writing a play. Because of their more private nature, few poems, particularly long-form poems, have been published.  The two longest works that scholars agree were written by Shakespeare are entitled Venus and Adonis and The Rape of Lucrece. Both dedicated to the Honorable Henry Wriothesley, Earl of Southampton, who seems to have acted as a sponsor and encouraging benefactor of Shakespeare's work for a brief time.  Both of these poems contain dozens of stanzas and comment on the depravity of unwanted sexual advances, showing themes throughout of guilt, lust, and moral confusion. In Venus and Adonis, an innocent Adonis must reject the sexual advances of Venus. Conversely in The Rape of Lucrece, the honorable and virtuous wife Lucrece is raped a character overcome with lust, Tarquin. The dedication to Wriothesley is much warmer in the second poem, suggesting a deepening of their relationship and Shakespeare's appreciation of his support.  A third and shorter narrative poem, A Lover's Complaint, was printed in the first collection of Shakespeare's sonnets. Most scholars agree now that it was also written by Shakespeare, though that was contested for some time. The poem tells the story of a young woman who is driven to misery by a persuasive suitor's attempts to seduce her. It is not regarded by critics to be his finest work.  Another short poem, The Phoenix and the Turtle, despairs the death of a legendary phoenix and his faithful turtle dove lover. It speaks to the frailty of love and commitment in a world where only death is certain.  There are 152 short sonnets attributed to Shakespeare. Among them, the most famous ones are Sonnet 29, Sonnet 71, and Sonnet 55. As a collection, narrative sequence of his Sonnets speaks to Shakespeare's deep insecurity and jealousy as a lover, his grief at separation, and his delight in sharing beautiful experiences with his romantic counterparts. However, few scholars believe that the sequence of the sonnets accurately depicts the order in which they were written. Because Shakespeare seemed to write primarily for his own private audience, dating these short jewels of literature has been next to impossible.  Within the sonnets Shakespeare seems to have two deliberate series: one describing his all consuming lust for a married woman with a dark complexion (the Dark Lady), and one about his confused love feelings for a handsome young man (the Fair Youth). This dichotomy has been widely studied and debated and it remains unclear as to if the subjects represented real people or two opposing sides to Shakespeare's own personality.  Though some of Shakespeare's poetry was published without his permission in his lifetime, in texts such as The Passionate Pilgrim, the majority of the sonnets were published in 1609 by Thomas Thorpe. Before that time, it appears that Shakespeare would only have shared his poetry with a very close inner-circle of friends and loved ones. Thorpe's collection was the last of Shakespeare's non-dramatic work to be printed before his death.  Critics have praised the sonnets as being profoundly intimate and meditating on the values of love, lust, procreation, and death. Nowaday, Shakespeare is ranked as all-time most popular English poets on history, along with Emily Dickinson, Robert Frost, and Walt Whitman.";

int main(){
  initFrequency(text);
  initTree();


//  showFrequency();
  showCodes();

  char *encodeString = encode(text, strlen(text));
  printf("%s\n", encodeString);

  return 0;
}
