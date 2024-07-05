// Fill out your copyright notice in the Description page of Project Settings.


#include "ArraySorter.h"

TMap<AActor*, float> UArraySorter::SortActorDistanceMap(TMap<AActor*, float> InActorDistanceMap)
{
	/*
	auto Comparator = [](const TPair<AActor*, float>& A, const TPair<AActor*, float>& B) {
		return A.Value < B.Value; // Compare values (int32)
	};

	InActorDistanceMap.ValueSort(Comparator);
	*/
	return InActorDistanceMap;
}
