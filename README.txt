$Id 


README.txt file
===============
Redmine Issuer does one thing: sends messages (ostensibly originating from your 
Drupal users) to a mailbox that, presumably, is checked periodically by a 
Redmine server.  These messages are formatted the way Redmine needs them to be 
in order to create new issues.  

Redmine Issuer contains a few options relating to Redmine issue classification 
which you will need to set to reflect the intersection of (the state of things 
in your Redmine install) and (the list of options you want to offer your Drupal
users).

Redmine Issuer sends emails originating from your Drupal users' email addresses.
This presumes that you have identical users in your Redmine install (well, users 
with identical email addresses) who are premitted to create new issue tickets.


Dependencies
============

None.

Incompatibilities
=================

None known.

Installation and Settings
=========================

Standard installation applies.  Check INSTALL.txt for some configuration notes.

General Settings are at Administer > Site configuration > Redmine ISsuer (
admin/settings/redmine_issuer).  You will need to visit this page initially and 
submit settings for the module to function.  There are six fields:

1. Redmine Mailbox
This is the destination email address to which Redmine Issues will be sent.

2. Redmine Project Identifier
This is the destination project *identifier*, not the friendly human-readble project name.

3. Trackers
By default populated with the default Redmine issue tracker names.

4. Statuses
By default populated with the default Redmine issue statuses.
You might want to use a subset or even just a single value, like "New."

5. Priorities
By default populated with the default Redmine issue priorities.
You might want to use only a subset or a single value, like "Normal."

6. Categories
Not required, but useful.  Project categories can be used to auto-assign issues to a given Redmine user.
There is no other way to assign new issues via email at this time.


Recent Changes
==============

2010-01-21  Created module.

2010-03-25  Added Redmine categories for automatic issue assignment.  
            We don't like un-assigned issues floating around.


