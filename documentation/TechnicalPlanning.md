# Technical Plan

## Objects

### Data Layer
#### ResumeComponent
A section of a resume. It can be any component as listed in the root-level README.md. 

There can be multiple levels of the resume component. Example:
- Profile Information
  - Name
  - Email
  - Phone
  - GitHub
  - LinkedIn

Each ResumeComponent stores keywords that will be useful in finding the relevance of the job requirements. It also stores the last relevant date, its type, as well as any text that comes along with it, and keywords.

All keywords should be in lowercase.

ResumeComponent should be flexible enough to allow users to create their own ResumeComponent without changing code. 

#### ResumeComponentRepository
The memory for the ResumeComponents. It should support CRUD of custom ResumeComponents, and fetch relevant ResumeComponents when a query with keywords are made.

It should also be able to fetch the various types of ResumeComponents for auto-completion.

#### ResumeComponentStore
This handles local storage read and write.

### Controller Layer

#### ResumeComponentController
Adding, Deleting, Updating a ResumeComponent

#### ResumeTypeController
Adding, Deleting, Updating a ResumeType

#### ResumeKeywordController
Updating a ResumeKeyWord

#### StorageActivationController
Saves to file

#### BuilderController
Builds a list of ResumeComponent

#### SearchController
Similar to BuilderController but without the resume.

#### ExitController
Handles cleanup and saving

#### CleanController
Handles Cleanup.

### Parse Layer

#### CommandParser
This should parse the user input for the following:
- Adding, Deleting, Updating a ResumeComponent
- Updating keywords
- Adding, deleting and updating types
- Searching by keyword
- Listing keywords and types
- Building a resume
- Exit and save
- Cleanup operations


It then hands the command over to the other parsers for further parsing.

#### AddParser
Parses the details of the `add` command

#### DeleteParser
Parses the details of the `rm` command

#### UpdateParser
Parses the details of the `update` command

#### ListParser
Parses the details of the `ls` command

#### SearchParser
Parses the details of the `search` command

#### BuildParser
Parses the details of the `build` command

#### CleanParser
Parses the details of the `clean` command

#### ExitParser
Parses the details of the `exit` command

### View Layer

#### OutputHandlers

#### InputHandlers