#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

/*
=========================================================
Problem: 355. Design Twitter
Topic: HashMap + HashSet + Heap (Priority Queue)
Difficulty: Medium

Approach:
- Store every user's tweets using a HashMap.
- Each tweet is stored as:
      {timestamp, tweetId}

- Maintain a global timestamp so tweets can be ordered
  chronologically.

- Store follow relationships using:
      followerId -> set of followeeIds

- For getNewsFeed(), use a max-heap to merge tweets from
  the user and everyone they follow.

- Initially, insert only the latest tweet from each relevant
  user into the heap.

- The heap stores:
      {timestamp, userId, tweetIndex}

- The most recent tweet is always at the top.

- After removing a tweet from the heap, insert the previous
  tweet from the same user.

- Continue until:
      1. The heap becomes empty, or
      2. 10 tweets have been collected.

Why Max-Heap?
- We need the most recent tweet at every step.
- A max-heap keeps the tweet with the largest timestamp
  at the top.

Why Store tweetIndex?
- After taking a user's latest tweet, we need to access
  that user's next older tweet.
- If the current index is i, the next tweet is at i - 1.

Key Pattern:
- This is a K-way Merge problem.
- Each user's tweets form a sorted list by timestamp.
- The heap merges these sorted lists while keeping only
  the newest candidate from each list.

Example:
User 1 tweets:
    (1, 101), (4, 104)

User 2 tweets:
    (2, 102), (5, 105)

Initial heap:
    (5, user2, index1)
    (4, user1, index1)

Pop user2's tweet 105.

Then insert user2's previous tweet:
    (2, user2, index0)

Heap now contains:
    (4, user1, index1)
    (2, user2, index0)

Continue until 10 tweets are collected.

Time Complexity:
- postTweet: O(1) average
- follow: O(1) average
- unfollow: O(1) average
- getNewsFeed:
      O(F log F + K log F)
  where F = number of relevant users
        K <= 10

Space Complexity:
- Tweets: O(T)
- Follow relationships: O(F)
- Heap: O(F)
- Overall: O(T + F)

Important:
- The user must always see their own tweets.
- Duplicate follows are prevented by unordered_set.
- unfollow() removes the follow relationship from the
  follower's set.

=========================================================
*/

class Twitter
{

    // userId -> vector of {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // followerId -> set of users they follow
    unordered_map<int, unordered_set<int>> following;

    // Global timestamp
    int timestamp = 0;

public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {

        tweets[userId].push_back({timestamp++,
                                  tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {

        // {timestamp, userId, tweetIndex}
        priority_queue<tuple<int, int, int>> pq;

        // Add user's own latest tweet
        if (!tweets[userId].empty())
        {

            int index = tweets[userId].size() - 1;

            pq.push({tweets[userId][index].first,
                     userId,
                     index});
        }

        // Add latest tweet of every followed user
        for (int followee : following[userId])
        {

            if (!tweets[followee].empty())
            {

                int index = tweets[followee].size() - 1;

                pq.push({tweets[followee][index].first,
                         followee,
                         index});
            }
        }

        vector<int> ans;

        // Get at most 10 most recent tweets
        while (!pq.empty() && ans.size() < 10)
        {

            int time = get<0>(pq.top());
            int user = get<1>(pq.top());
            int index = get<2>(pq.top());
            pq.pop();

            // Add current tweet to feed
            ans.push_back(
                tweets[user][index].second);

            // Add next older tweet from the same user
            if (index > 0)
            {

                int prevIndex = index - 1;

                pq.push({tweets[user][prevIndex].first,
                         user,
                         prevIndex});
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId)
    {

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {

        following[followerId].erase(followeeId);
    }
};