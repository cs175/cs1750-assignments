**CS 1750 GitHub Guide for Problem Sets**

**Vihaan Gupta**  
**Fall 2026**

This guide explains how to set up and use your GitHub repository for CS 1750 problem sets.

The course maintains a central repository:

[https://github.com/cs175/cs1750-assignments](https://github.com/cs175/cs1750-assignments)

This repository contains the starter code for all problem sets in separate folders.

For example:

```
cs1750-assignments/
├── asst1/
├── asst2/
└── ...
```

For your own work, you will maintain a separate private GitHub repository.

You may complete problem sets either individually or with one partner. You should continue using the same private repository for as long as your individual/pair grouping stays the same.

If your partner changes, or if you switch between working individually and working with a partner, you must create a new private repository.

1. **Overview**

Your private repository will contain your completed assignments under each asst’s respective folder.

For example:

```
cs1750-lastname1-lastname2/
  ├── asst1/
  ├── asst2/
  └── asst3/
```

You should use one repository for as long as your collaboration group remains unchanged.

For example:

```
PSet 1: Gupta + Irger
PSet 2: Gupta + Irger
PSet 3: Gupta + Smith
```

In this case:

```
cs1750-gupta-irger/
└── assignments/
    ├── pset1/
    └── pset2/

cs1750-gupta-smith/
└── assignments/
    └── pset3/
```

The old repository should remain unchanged once the collaboration group changes.

This ensures that a new partner does not gain access to problem sets completed with a previous partner.

The steps below concretely outline the GitHub Workflow for the course.

2. **Clone the Course Repository**

If you have not already done so, clone the course repository:

```shell
git clone git@github.com:cs175/cs1750-assignments.git
```

Then move into it on your local machine:

```shell
cd cs1750-assignments
```

You only need to clone the course repository once.

Before starting each new problem set, update your local copy:

```shell
git pull
```

3. **Create Your Private Repository**

When starting the course, or whenever your collaboration group changes, create a new private GitHub repository. To create a new repository, go to your GitHub account and click the green button labelled “New” to create a new repository.

Repository names should follow this naming convention.

If working individually:

```
cs1750-LASTNAME
```

For example:

```
cs1750-gupta
```

If working with a partner:

```
cs1750-LASTNAME1-LASTNAME2
```

For example:

```
cs1750-gupta-irger
```

Use lowercase letters in repository names.

The repository must be set to Private.

The repository should initially be empty.

4. **Clone Your Private Repository**

After creating your private GitHub repository, clone it to your local machine.

For example:

```shell
git clone https://github.com/YOUR-USERNAME/cs1750-gupta-irger.git
```

Then move into the repository:

```shell
cd cs1750-gupta-irger
```

5. **Copy a Problem Set into Your Repository**

Suppose you are starting Problem Set 1\.

First, update your local copy of the course repository:

```shell
cd path/to/cs1750-assignments
git pull
```

Then copy the relevant problem set folder into the `assignments` folder of your private repository:

```shell
cp -r asst1 ../cs1750-gupta-irger/asst1
```

Your private repository should now look something like:

```
cs1750-gupta-irger/
    └── asst1/
        ├── README.md
        ├── lib
        ├── shaders
        └── ...
```

You should do all of your work inside the copied `asst1` folder.

Do not modify the original files inside `cs1750-dev`.

6. **Commit and Push the Starter Code**

Move into your private repository:

```shell
cd ../cs1750-gupta-irger
```

Add the new assignment:

```shell
git add pset1
```

Create a commit:

```shell
git commit -m "Add PSet 1 starter code"
```

Push the repository:

```shell
git push origin main
```

Your private GitHub repository should now contain the Problem Set 1 starter code under:

```
pset1
```

7. **Add Course Staff as Collaborators**

Because your repository is private, you must add the course staff as collaborators.

On GitHub, open your private repository and go to:

```
Settings → Collaborators
```

Add the following GitHub usernames as collaborators: vihaann06, stevengortler, alexandrairger.

You only need to add course staff once for each private repository you create.

If you continue using the same repository for multiple problem sets, you do not need to add the course staff again.

8. **Working in a pair**

If you are completing a problem set with a partner, your pair should use exactly one shared private repository.

For example:

```
cs1750-gupta-irger
```

Do not create two separate repositories for the same pair.

One partner should create the private repository and add:

• Their partner

• The course staff

as collaborators.

On GitHub, open the repository and go to:

```
Settings → Collaborators
```

Invite your partner using their GitHub username.

Your partner should accept the invitation before continuing.

9. **Second Partner Setup**

The second partner should clone the shared private repository:

```shell
git clone https://github.com/PARTNER-USERNAME/cs1750-gupta-irger.git
```

Then move into it:

```shell
cd cs1750-gupta-irger
```

Both partners now have local copies of the same repository.

Before beginning work, pull your partner's latest changes:

```shell
git pull origin main
```

After making changes:

```shell
git add .
git commit -m "Describe what you changed"
git push origin main
```

10. **Changing Partners**

If your partner changes, you must create a new private repository.

For example, suppose you completed:

```
PSet 1: Gupta + Irger
PSet 2: Gupta + Irger
```

using:

```
cs1750-gupta-irger
```

For Problem Set 3, suppose you work with Smith instead.

You should create a new repository:

```
cs1750-gupta-smith
```

**Do not add Smith to `cs1750-gupta-irger`.**

The old repository contains work completed with your previous partner and should remain accessible only to that original collaboration group and course staff.

Your repositories would look like:

```
cs1750-gupta-irger/
    ├── pset1/
    └── pset2/

cs1750-gupta-smith/
    └── pset3/
```

Similarly, if you switch from working with a partner to working individually, create a new repository:

```
cs1750-gupta
```

If you switch from working individually to working with a partner, create a new pair repository.

11. **Important Privacy Rules**

All student repositories must be private.

Do not:

• Make your repository public.

• Fork the course repository and place your solutions in a public fork.

• Upload your solutions to another public repository.

• Add students who are not part of the collaboration group.

• Add a new partner to a repository containing work from a previous collaboration group.

• Look at or copy another student's private repository.